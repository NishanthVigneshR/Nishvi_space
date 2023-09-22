#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]) {
	pid_t fd = 0;
	int ret = 0;
	char buf[50] = {0};
	printf("This is client process and pid is %d\n", getpid());

	fd = open("/tmp/demofile", O_RDONLY);

	if (fd == -1) {
		printf("open system call failed\n");
		perror("");
		exit(-1);
	}

	while (1) {
		memset(buf, '\0', sizeof(buf));
		ret = read(fd, buf, sizeof(buf));
		if (ret == -1) {
			printf("read system call failed\n");
			exit(0);
		}
		printf("%d bytes of data received from server and buffer is : %s\n", ret, buf);
	}
	close(fd);
	printf("Terminating client process\n");
	exit(0);
}

/* Output 1 : named pipe file is not present. At that if I try run client process means, open call will fail.
 *
 * [root@localhost FIFO]# ./fifo_client
 * This is client process and pid is 6663
 * open system call failed
 * No such file or directory
 */

/* Output 2 : In the above scenario, if I make client run without namedpipe file and even if I'm skipping error handling.
 * while loop will be executed infinitely.
 */

/* Output 3: Established full communication between server and client.
 * Please find the output below.
 *
 * Server:
 * [root@localhost FIFO]# ./fifo_server
 * mkfifo system call executed successfully
 * This is server process and pid is 7162
 * file opened successfully and fd is 3
 * Please enter the buffer to be written :
 * Hello Client!!!
 * 16 bytes of data written successfully in named pipe[3]
 * Please enter the buffer to be written :
 * This is Server
 * 15 bytes of data written successfully in named pipe[3]
 * Please enter the buffer to be written :
 * We are communicating by using FIFO
 * 35 bytes of data written successfully in named pipe[3]
 * Please enter the buffer to be written :
 * This is one of the IPC concept
 * 31 bytes of data written successfully in named pipe[3]
 * Please enter the buffer to be written :
 * Thanks buddy for develping this!!
 * 34 bytes of data written successfully in named pipe[3]
 * Please enter the buffer to be written :
 * Bye!! All the best and keep going buddy!
 * 39 bytes of data written successfully in named pipe[3]
 * Please enter the buffer to be written :
 * 2 bytes of data written successfully in named pipe[3]
 * Please enter the buffer to be written :
 *
 * ------------------------------------------------------------------
 *
 *  Client:
 *  [root@localhost FIFO]# ./fifo_client
 *  This is client process and pid is 7163
 *  16 bytes of data received from server and buffer is : Hello Client!!!
 *
 *  15 bytes of data received from server and buffer is : This is Server
 *
 *  35 bytes of data received from server and buffer is : We are communicating by using FIFO
 *
 *  31 bytes of data received from server and buffer is : This is one of the IPC concept
 *
 *  34 bytes of data received from server and buffer is : Thanks buddy for develping this!!
 *
 *  41 bytes of data received from server and buffer is : Bye!! All the best and keep going buddy!
 */

