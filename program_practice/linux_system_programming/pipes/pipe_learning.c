#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int ret = 0;
	int fd[2] = {0};
	char buf[50] = {'\0'};

	ret = pipe(fd);

	if (ret == -1) {
		printf("pipe system call failed\n");
		perror("");
		exit(0);
	}

	sprintf(buf, "Hello Buddy! Learning about pipes concept");
	ret = write(fd[1], buf, strlen(buf));
	if (ret == -1) {
		printf("write system call failed\n");
		perror("");
	} else {
		printf("%d bytes of data written to pipe\n", ret);
	}

	memset(buf, '\0', sizeof(buf));
	ret = read(fd[0], &buf, sizeof(buf));
	if (ret == -1) {
		printf("read system call failed\n");
		perror("");
	} else {
		printf("%d bytes of data read successfully and data is %s\n", ret, buf);
	}
	sleep(60);
	exit(0);
}

/* Output:
 * [root@localhost pipes]# ./pipe_learning
 * 41 bytes of data written to pipe
 * 41 bytes of data read successfully and data is Hello Buddy! Learning about pipes concept
 */
