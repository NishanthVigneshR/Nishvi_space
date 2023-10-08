/* Steps:
 *
 * 1] Create the client socket
 * 2] Initialize server info
 * 3] Send and receive the data
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

#define COMMUNICATION_PORT 2500
#define LOCAL_IP "127.0.0.1"

void setup_udp_client() {
	int fd = 0;
	struct sockaddr_in server_info;
	struct hostent * host;
	int ret = 0;
	char buffer[20]= {'\0'};
	int addrlen = 0;

	fd = socket (AF_INET, SOCK_DGRAM, 0);
	if (fd == -1) {
		perror("Creating client socket failed\n");
		exit(0);
	}
	printf("Client socket created successfully and fd : %d\n", fd);

	server_info.sin_family = AF_INET;
	server_info.sin_port   = COMMUNICATION_PORT;
	
	host  = (struct hostent *) gethostbyname(LOCAL_IP);
	server_info.sin_addr   = *((struct in_addr *) host->h_addr);

	while (1) {
		printf("Send the data to server\n");

		memset (buffer, '\0', sizeof(buffer));
		printf("Enter the data\n");
		scanf("%s", buffer);
		ret = sendto(fd, (char *) buffer, strlen(buffer), 0, (struct sockaddr *)&server_info, sizeof(struct sockaddr));
		if (ret == -1) {
			perror("Sending data to server failed : ");
			exit(0);
		}
		printf("%d bytes of data sent successfully\n", ret);
#if 0
		memset (buffer, '\0', sizeof(buffer));
		ret = recvfrom(fd, (char *)buffer, sizeof(buffer), 0, (struct sockaddr *) &server_info, &addrlen);
		if (ret == -1) {
			perror("receiving data from server failed : ");
			exit(0);
		}
		printf("%d bytes of data received successfully\n", ret);
#endif
	}

}

int main() {
	printf("This is client process and pid : %d\n", getpid());
	setup_udp_client();
}
