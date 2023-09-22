#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
	printf("This is parent process and pid is %d\n", getpid());
	int fd[2] = {0}; //fd[0] for read and fd[1] for write
	char buf[60] = {'\0'}; //I will write this buf from one end and will read in another end
	int ret = 0;
	pid_t cpid = 0;

	ret = pipe(fd);
	if (ret == -1) {
		printf("pipe system call failed\n");
		perror("Error :");
		exit(0);
	}

	cpid = fork();
	if (cpid == -1) {
		printf("fork system call failed\n");
		perror("Error ");
		exit(0);
	}

	if (cpid == 0) {
		printf("This is child process and pid is %d\n", getpid());
		printf("Parent process of the child process is %d\n", getppid());
		printf("Child process : Write the needed data in pipe\n");
		sprintf(buf, "pipes programs with fork call");
		ret = write(fd[1], buf, strlen(buf));
		if (ret == -1) {
			printf("write system call failed\n");
			perror("Error is ");
		} else {
			printf("%d bytes of data written successfully to pipe\n", ret);
		}
		printf("Terminating child process\n");
		exit(0);
	}

	printf("This is parent process [%d] and successfully created child process with pid [%d]\n", getpid(), cpid);
	ret = wait(NULL);
	printf("Parent process: Buffer written in child process is (see below)\n");
	memset (buf, '\0', sizeof(buf));
	ret = read(fd[0], &buf, sizeof(buf));
	if (ret == -1) {
		printf("read system call failed\n");
		perror("Error is ");
	} else {
		printf("%d bytes of data read successfully and data is %s\n", ret, buf);
	}
	printf("Terminating parent process\n");
	exit(0);
}

/* Output :
 * [root@localhost pipes]# ./pipe_learning
 * This is parent process and pid is 34128
 * This is parent process [34128] and successfully created child process with pid [34129]
 * This is child process and pid is 34129
 * Parent process of the child process is 34128
 * Child process : Write the needed data in pipe
 * 29 bytes of data written successfully to pipe
 * Terminating child process
 * Parent process: Buffer written in child process is (see below)
 * 29 bytes of data read successfully and data is pipes programs with fork call
 * Terminating parent process
 */



