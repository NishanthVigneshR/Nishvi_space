// Here, I will create the named pipe and will write the data in the file.

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int ret = 0;
	int fd = 0;
	char buf[50] = {0};
	char * file = "/tmp/demofile";
	
	ret = mkfifo(file, 0660);
	if (ret == -1) {
		printf("creating named pipe failed\n");
		perror("");
		exit(-1);
	}
	printf("mkfifo system call executed successfully\n");

	printf("This is server process and pid is %d\n", getpid());

	//fd = open (file, O_WRONLY | O_NONBLOCK);  //open call blocked when write end is absent. To avoid blocking I provided O_NONBLOCK mode.
	fd = open(file, O_WRONLY); //Now, until the read end is getting connected open call will be blocked.
	if (fd == -1) {
		printf("open system call failed\n");
		perror("");
		exit(-1);
	}
	printf("file opened successfully and fd is %d\n", fd);

	while (1) {
	    //sprintf(buf, "This data is sent by server process\n");
	    memset(buf, '\0', sizeof(buf));
	    printf("Please enter the buffer to be written : \n");
	    fgets (buf, 40, stdin);
	    ret = write(fd, buf, strlen(buf));
	    if (ret == -1) {
		printf("write system call failed\n");
		perror("");
	    } else {
		printf("%d bytes of data written successfully in named pipe[%d]\n", ret, fd);
   	    }
	}
	close(fd);
	printf("Terminating server\n");
	exit(0);
}


/* Output 1 : Initially I just written server code and compiled server code alone.
 * When I executed, I observed open() call got blocked.
 * I hand no idea and given O_NONBLOCK mode as arguments.
 * In this case, open call not blocked but it failed with EXIO error (No such device or address).
 * I have checked 'man 7 fifo' page and I've got to know, when we are handling namedpipe
 *
 * open() system call will be blocked until both the read and write end active. If either one end is not active,
 * open() call will behave like block call.
 *
 * I tried to write even if open call failed due to absence of read end fd.
 * I got 'Bad file descriptor' error.
 *
 * Output:
 * [root@localhost FIFO]# ./fifo_server
 * mkfifo system call executed successfully
 * This is server process and pid is 5778
 * open system call failed
 * No such device or address
 * file opened successfully and fd is -1
 * hello
 * write system call failed
 * Bad file descriptor
 */


/* Output 2: Established full communication between server and client.
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
 * -----------------------------------------------------------------
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
 *
 */
