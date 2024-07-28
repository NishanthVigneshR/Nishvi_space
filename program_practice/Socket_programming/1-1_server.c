/* Steps:
 * 1] Initialize the variables.
 * 2] Create a master socket.
 * 3] Bind the info about the traffic which server will accept.
 * 4] Assign maximum number of possible active client connections by using listen().
 * 5] Fill the fs_set parameter with master socket.
 * 6] Invoke select system call and wait for client requests.
 * 7] Check if master socket is set. If yes, connection request message is received and invoke accept() system call.
 * 8] If master socket is not set, service request message received. Handle the message and send the result back to the client.
 * 9] Close the socket.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>  // Need this for select and fd_set.
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define SERVER_PORT 3000 //Server will use 1500 port for communication.

void setup_tcp_server() {
#if 1
	// 1] Initialize the variables.
	int master_socket = 0;
	struct sockaddr_in server_addr; // Structure to hold server IP, type and port information.
	int ret = 0;
	fd_set readfds; 
	/* Stores all the fd's and select() call monitors this fd_set and will unblock once
	 * any one of the available fd set.
	 */
	struct sockaddr_in client_addr; // Structure to hold Client IP, type and port information.
	int addrlen = 0;
	int comm_client_fd = 0;
	char databuffer[20] = {'\0'};
#endif

#if 2
	// 2] Creating the master socket.
	master_socket = socket(AF_INET, SOCK_STREAM, 0); 
	/* In place of 0, I can give IPPROTO_TCP. But, if we mention 0 it'll take default value based on socket type.
	 * AF_INET represents IPv4 communication. For UDP, SOCK_DGRAM and IPPROTO_UDP will be used.
	 */
	if (master_socket == -1) {
		printf("Creating master socket failed\n");
		perror("");
		exit(-1);
	}
	printf("Created master socket : %d\n", master_socket);
#endif

#if 3
	// 3] Bind the info about the type of packets, server can receive.
	/* 
	 * Syntax of bind call : int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	 *
	 * where, arg [1] represents master socket fd,
	 * 	  arg [2] represents the Server Info (Family, IP and Port).
	 * 	  arg [3] represents size of the 2nd argument. (Here, sizeof (struct sockaddr).
	 *
	 * Arg[2] will be filled by the structure struct sockaddr_in.
	 *
	 * 	struct sockaddr_in {
         *          sa_family_t    sin_family; // address family: AF_INET 
         *          in_port_t      sin_port;   // port in network byte order 
         *          struct in_addr sin_addr;   // internet address
         *      };

         *      // Internet address
         *      struct in_addr {
         *          uint32_t       s_addr;     // address in network byte order 
         *      };
	 */
	
	server_addr.sin_family      = AF_INET;
	server_addr.sin_port        = SERVER_PORT; //1500
	server_addr.sin_addr.s_addr = INADDR_ANY;

	/* In the server there can muliple interfaces and packets can be received from every interfaces.
	 * So, if we need specific interface to communicate, we need to provide that IP address alone in network byte order.
	 * If we need to accept packets from all the interfaces means we can simply use INADDR_ANY macro.
	 */

	ret = bind (master_socket, (struct sockaddr *) &server_addr, sizeof (struct sockaddr));

	printf("Return value of bind call : %d\n", ret);
	if (ret == -1) {
		printf("Binding the master socket failed\n");
		perror("");
	}
#endif

#if 4
	// 4] By using listen() call, initialize maximum allowed client connections.
	// Syntax : listen (int sock_fd, int num);
	
	ret = listen (master_socket, 5); // maximum 5 client connections allowed
	if (ret == -1) {
		printf("Listen call failed\n");
		perror("");
	}
#endif

#if 510
	/* Since this is one-to-one communication, we are going to create the server in such a way that
	 * fd_set can hold at max 2 fd.
	 * 1] master socket fd and 2] client communication fd
	 */

	while (1) {
#if 5
		//  5] Fill the fs_set parameter with master socket.
		/* Assume, I'm connecting two clients one after another. So, each time when the new client comes
		 * we need to clear the exiting fd_set. Old client entry should be completely vanished.
		 * There are few macros which will help us to achieve it.
		 */
		FD_ZERO (&readfds);
		FD_SET (master_socket, &readfds);
#endif

#if 6
		/* Select() call will block the execution until any one of the fd present in fd_set get's request.
		 * In this implementation, once client sends connect we will get request to master_socket.
		 *
		 * Syntax: 
		 * int select(int nfds, fd_set *_Nullable restrict readfds,
                 *  fd_set *_Nullable restrict writefds,
                 *  fd_set *_Nullable restrict exceptfds,
                 *  struct timeval *_Nullable restrict timeout);
		 *
		 *  nfds represents highest fd present in the fd_set plus 1. (Here, master_socket+1)
		 *  timeout represents the blocking time.
		 *
		 *  Syntax :
		 *  struct timeval {
                 *     time_t      tv_sec;         // seconds 
                 *     suseconds_t tv_usec;        // microseconds
                 *  };
		 */

		ret = select (master_socket+1, &readfds, NULL, NULL, NULL);
		if (ret == -1) {
			printf("Select system call failed\n");
			perror("");
		}
		printf("Select call unblocked and return is %d\n", ret);	
#endif

#if 7
		//7]Check if master socket is set.If yes, connection request message is received and invoke accept() system call.

		if (FD_ISSET(master_socket, &readfds)) {
			printf("Received new client connection request\n");
			comm_client_fd = accept (master_socket, (struct sockaddr *) &client_addr, &addrlen);
			if (comm_client_fd == -1) {
				printf("accept system call failed\n");
				perror("");
				exit(-1);
			}
			printf("New connection request accepted and fd : %d\n", comm_client_fd);
			printf("Client info : IP : %s and port : %u\n",
					inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
#endif

#if 8
			// 8] service request message received. Handle the message and send the result back to the client.
			while (1) {
			    memset(databuffer, '\0', sizeof(databuffer));
			    printf("Looking for an service request messages from client\n");

			    /* By using recvmsg (or) recvfrom() calls, we can receive the data from client.
			     * ssize_t recvfrom(int sockfd, void buf[restrict .len], size_t len,
                             * 		int flags,
                             * 		struct sockaddr *_Nullable restrict src_addr,
                             * 		socklen_t *_Nullable restrict addrlen);
			     *
       			     * ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);
			     */
			    ret = recvfrom (comm_client_fd, (char *) databuffer, sizeof (databuffer), 0, (struct sockaddr *) &client_addr, &addrlen);
			    if (ret == -1) {
				    printf("Receiving data from client failed\n");
				    perror("");
			    }
			    printf("%d bytes of data received successfully and data is %s\n", ret, databuffer);

			    if (strcmp(databuffer, "Terminate") == 0) {
				    printf("Terminating the connection\n");
				    close (comm_client_fd);
				    break;
			    }
			    ret = sendto (comm_client_fd, "Acknowledged", 13, 0, (struct sockaddr *) &client_addr, sizeof(struct sockaddr));
			    if (ret == -1) {
				    printf("Replying back to client failed\n");
				    perror("");
			    }
			    printf("%d bytes of data sent successfully\n", ret);
			}
#endif

		}
	}
#endif
}

int main() {
	printf("This is server process and pid : %d\n", getpid());
	setup_tcp_server();
}

/* Output:
 * [root@localhost Socket_programming]# ./server
This is server process and pid : 13097
Created master socket : 3
Return value of bind call : 0
Select call unblocked and return is 1
Received new client connection request
New connection request accepted and fd : 4
Client info : IP : 48.0.0.0 and port : 0
Looking for an service request messages from client
5 bytes of data received successfully and data is hello
13 bytes of data sent successfully
Looking for an service request messages from client
6 bytes of data received successfully and data is Hey!!!
13 bytes of data sent successfully
Looking for an service request messages from client
9 bytes of data received successfully and data is Terminate
Terminating the connection


Select call unblocked and return is 1
Received new client connection request
New connection request accepted and fd : 4
Client info : IP : 48.0.0.0 and port : 0
Looking for an service request messages from client
5 bytes of data received successfully and data is Hello
13 bytes of data sent successfully
Looking for an service request messages from client
9 bytes of data received successfully and data is Terminate
Terminating the connection
*/
