/* Steps:
 * 1] Create the master socket.
 * 2] Bind the incoming packets info.
 * 3] Initialize maximum number of possible pending requests by using listen()
 * 4] Add master socket in fd_set.
 * 5] By using select call, wait for client requests.
 * 6] If it's connection initiation request, accept it.
 * 7] If it's service request, handle the request and send the reply back.
 */

/* Steps to clear the fd_set, add entry to fd_set.
 *
 * Initialize one array and store all the fd's in it.
 * From that array, re-initialize the fd_set on every iteration.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TCP_PORT 3000
#define MAX_CONNECTIONS 15
int fd_array[MAX_CONNECTIONS];

void initialize_fd_array(int * array) {
	int i = 0;
	for (i = 0;i < MAX_CONNECTIONS; i++)
		array[i] = -1;
}

void add_fd_to_array (int * array, int fd) {
	int i = 0;
	while (array[i] != -1) {
		i++;
	}
	array[i] = fd;
	printf("added fd %d to array\n", array[i]);
}

void fill_fd_set (fd_set * fds) {
	int  i = 0;

	FD_ZERO(fds);
	while (fd_array[i] != -1) {
		FD_SET(fd_array[i], fds);
		i++;
	}
}

int get_max_fd (int * array) {
	int max = 0;
	int i = 0;
	while (array[i] != -1) {
		if (array[i] > max) {
			max = array[i];
		}
		i++;
	}
	return max;
}

void remove_fd_from_array (int fd, fd_set * fds) {
	int i = 0;
	int j = 0;
	while (fd_array[i] != -1) {
		if (fd_array[i] == fd) {
			FD_CLR (fd_array[i], fds);
			printf("Removing fd %d from array\n", fd_array[i]);
			for (j = i+1; j < MAX_CONNECTIONS-1; j++) {
				fd_array[i++] = fd_array[j];
			}
			fd_array[i] = -1;
		}
		i++;
	}
}

void setup_multi_clients_handling_tcp_server() {
	int master_socket = 0;
	int ret = 0;
	struct sockaddr_in server_info;
	fd_set readfds;
	int max_fd = 0;
	int comm_client_fd = 0;
	int addrlen = 0;
	struct sockaddr_in client_info;
	int i = 0;
	char buffer[20] = {'\0'};

	master_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (master_socket == -1) {
		printf("Creating master socket failed\n");
		perror("");
		exit(-1);
	}
	printf("Master socket created successfully and pid : %d\n", master_socket);

	server_info.sin_family       = AF_INET;
	server_info.sin_port         = TCP_PORT;
	server_info.sin_addr.s_addr  = INADDR_ANY;

	ret = bind(master_socket, (struct sockaddr *) &server_info, sizeof(struct sockaddr));
	if (ret == -1) {
		printf("Binding the socket with the server info failed\n");
		perror("");
	}
	printf("Socket initialized with server info successfully and ret : %d\n", ret);

	ret = listen (master_socket, 5);
	if (ret == -1) {
		printf("Initializing master socket with 5 active connections failed\n");
		perror("");
	}
	printf("Master socket initialized successfully with 5 listeners and ret - %d\n", ret);

	initialize_fd_array(fd_array);
	add_fd_to_array(fd_array, master_socket);

	while (1) {
		fill_fd_set (&readfds);

		max_fd = get_max_fd (fd_array);
		printf("maximum fd present : %d\n", max_fd);
		ret = select (max_fd+1, &readfds, NULL, NULL, NULL);

		if (ret == -1) {
			printf("select system call failed\n");
			perror("");
			break;
		}
		printf("Select system call success and return : %d\n", ret);

		if (FD_ISSET (master_socket, &readfds)) {
			printf("Master socket is activated, connection initiation request received\n");
			comm_client_fd = accept(master_socket, (struct sockaddr *) &client_info, &addrlen);

			if (comm_client_fd == -1) {
				printf("Accepting the client connection request failed\n");
				perror("");
				continue;
			}
			printf("Accept call success and client fd : %d\n", comm_client_fd);
			add_fd_to_array(fd_array, comm_client_fd);
		} else {
			printf("Service request message received\n");
			memset (buffer, '\0', sizeof (buffer));
			while (fd_array[i] != -1) {
				if (FD_ISSET (fd_array[i], &readfds)) {
					printf("Service request received from fd : %d\n", fd_array[i]);
					ret = recvfrom (fd_array[i], (char *)buffer, sizeof (buffer), 0 , (struct sockaddr *) &client_info, &addrlen);
					if (ret == -1) {
						printf("Receiving data from client failed\n");
						perror("");
						break;
					}
					printf("Client is %s : %u\n", inet_ntoa(client_info.sin_addr), ntohs(client_info.sin_port));
					printf("Received %d bytes of data and data : %s\n", ret, buffer);

					if (strcmp (buffer, "Terminate") == 0) {
						printf("Terminating the server connection for fd : %d\n", fd_array[i]);
						remove_fd_from_array(fd_array[i], &readfds);
						break;
					}
					ret = sendto (fd_array[i], "Acknowledged", 13, 0, (struct sockaddr *) &client_info, sizeof (struct sockaddr));
					if (ret == -1) {
						printf("Sending response back to client failed\n");
						perror("");
						break;
					}
					printf("%d bytes of data sent successfully to client [%d]\n", ret, fd_array[i]);
					break;
				}
				i++;
			}
		}
	}
}

int main() {
	printf("This is server process-%d and can handle multiple clients at the same time\n", getpid());
	setup_multi_clients_handling_tcp_server();
	return 0;
}
