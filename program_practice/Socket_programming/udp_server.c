/* Steps:
 * UDP transmission is connection-less transmission.
 * There can be packet loss.
 *
 * 1] Create the server socket.
 * 2] Bind the socket with preferred packet information.
 * 3] Receive the message
 * 4] Send the response [if needed]
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

#define COMMUNICATION_PORT 2500

void setup_udp_server() {
	int fd = 0;
	struct sockaddr_in server_info;
	int ret = 0;
	struct sockaddr_in client_info;
	int addrlen = 0;
	char buffer[20] = {'\0'};

	fd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (fd == -1) {
		printf("Creating the socket failed\n");
		perror("");
		exit(0);
	}

	server_info.sin_family = AF_INET;
	server_info.sin_port   = COMMUNICATION_PORT;
	server_info.sin_addr.s_addr = INADDR_ANY;

	ret = bind (fd, (struct sockaddr *) &server_info, sizeof(struct sockaddr));

	if (ret == -1) {
		perror("bind call failed : ");
		exit(0);
	}
	printf("Socket initialized with server info and ret : %d\n", ret);

	while (1) {
		printf("Waiting for data from clients\n");
		memset(buffer, '\0', sizeof(buffer));
		ret = recvfrom (fd, (char *)buffer, sizeof(buffer), 0, (struct sockaddr *)&client_info, &addrlen);

		if (ret == -1) {
			perror("Receiving data from client failed : ");
			exit(0);
		}

		printf("%d bytes of data received successfully and data : %s\n", ret, buffer);

		if (strcmp (buffer, "Terminate") == 0) {
			printf("Terminating the connection\n");
			close(fd);
		}
#if 0
		memset(buffer, '\0', sizeof(buffer));
		int len = sizeof(struct sockaddr);
		strcpy(buffer, "acknowledge");
		ret = sendto (fd, (char *)buffer, strlen(buffer), 0, (struct sockaddr *)&client_info, len);
		if (ret == -1) {
			perror("Sending msg to client failed : ");
			exit(0);
		}
		printf("%d bytes of data sent successfully\n", ret);
#endif
	}
}

int main() {
	printf("This is server process and pid : %d\n", getpid());
	setup_udp_server();
}
