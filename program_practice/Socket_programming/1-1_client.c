/* Steps:
 * 1] Initialize the variables.
 * 2] Create the socket for client.
 * 3] Specify server information.
 * 4] Send connection initiation request to server.
 * 5] Send service requests to server
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

#define PORT 3000
#define SERVER_ADDR "127.0.0.1"

void setup_tcp_client() {
#if 1
	// 1] Variable initialization.
	int ret = 0;
	int client_fd = 0;
	struct sockaddr_in server_info;
	struct hostent * host = NULL;
	char buffer[20] = {'\0'};
	int addrlen = 0;
#endif

#if 2
	// 2] create client socket
	client_fd = socket (AF_INET, SOCK_STREAM, 0);
        if (client_fd == -1) {
	    printf("Creating client socket failed\n");
	    perror("");
	    exit(0);
	}
	printf("Client socket created successfully and pid : %d\n", client_fd);
#endif

#if 3
	//3]  Specify server information.
	/* We need to fill sockaddr_in (Family, IP and port).
	 * Here, I'm going to run server and client both in same system.
	 * By using local host address (127.0.0.1) we can communicate with server.
	 */
	server_info.sin_family = AF_INET;
	server_info.sin_port   = PORT;

	/* By using gethostbyname() call, we can fetch the host entry.
	 * It's datatype is struct hostent.
	 *
	 * struct hostent {
         *     char  *h_name;            // official name of host
         *     char **h_aliases;         // alias list 
         *     int    h_addrtype;        // host address type 
         *      int    h_length;          // length of address 
         *       char **h_addr_list;       // list of addresses
         *   }
         *   #define h_addr h_addr_list[0] // for backward compatibility
	*/
	host = (struct hostent *) gethostbyname(SERVER_ADDR);
	server_info.sin_addr = *((struct in_addr *) host->h_addr);
#endif

#if 4
	// 4] Send connection initiation request to server
	
	ret = connect (client_fd, (struct sockaddr *) &server_info, sizeof(struct sockaddr));
	if (ret == -1) {
		printf("Sending connection initiation request failed\n");
		perror("");
	}
	printf("Connection initiated successfully with server and ret : %d\n", ret);
#endif

#if 5
	while (1) {
		memset(buffer, '\0', sizeof(buffer));
		printf("Enter the data to be sent to server\n");
		scanf("%s", buffer);

		ret = sendto(client_fd, (char *) buffer, strlen(buffer), 0, (struct sockaddr *) &server_info, sizeof(struct sockaddr));
		if (ret == -1) {
			printf("Sending data to server failed\n");
			perror("");
		}
		printf("%d bytes of data sent successfully to server\n", ret);

		if (strcmp(buffer, "Terminate") == 0) {
			printf("Terminating the connection from client\n");
			close(client_fd);
			break;
		}

		memset(buffer, '\0', sizeof (buffer));
		ret = recvfrom (client_fd, (char *) &buffer, sizeof (buffer), 0, (struct sockaddr *)&server_info, &addrlen);
		if (ret == -1) {
			printf("Failed to receive response from server\n");
			perror("");
		}
		printf("%d bytes of data received and data : %s\n", ret, buffer);
	}
#endif
}

int main() {
	printf("This is client process and pid : %d\n", getpid());
	setup_tcp_client();
}

/* Output:
 *
 * [root@localhost Socket_programming]# ./client
This is client process and pid : 13098
Client socket created successfully and pid : 3
Connection initiated successfully with server and ret : 0
Enter the data to be sent to server
hello
5 bytes of data sent successfully to server
13 bytes of data received and data : Acknowledged
Enter the data to be sent to server
Hey!!!
6 bytes of data sent successfully to server
13 bytes of data received and data : Acknowledged
Enter the data to be sent to server
Terminate
9 bytes of data sent successfully to server
Terminating the connection from client
[root@localhost Socket_programming]#
[root@localhost Socket_programming]# ./client
This is client process and pid : 13105
Client socket created successfully and pid : 3
Connection initiated successfully with server and ret : 0
Enter the data to be sent to server
Hello
5 bytes of data sent successfully to server
13 bytes of data received and data : Acknowledged
Enter the data to be sent to server
Terminate
9 bytes of data sent successfully to server
Terminating the connection from client
*/
