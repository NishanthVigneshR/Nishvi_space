/* In this program, I will check what will happen to offset if I share same file between parent and child process.
 * Both parent and child will have separate fd table. But, the fd values will be duplicate and it will same.
 * Changing the offset in child will reflect in parent process as well. Let's verify.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
	pid_t cpid = 0;
	int fd = 0;
	int ret = 0;
	char buf[15] = {0};
	printf("This is parent process and pid [%d]\n", getpid());
	fd = open("Demofile", O_RDONLY);
	if (fd == -1) {
		printf("open call failed\n");
		perror("Error is :");
		exit(-1);
	}
	cpid = fork();
	if (cpid == -1) {
		printf("fork system call failed\n");
		exit(-1);
	}
	if (cpid == 0) {
		printf("This is child process and pid-%d\n", getpid());
		printf("Parent process of this child is %d\n", getppid());
		printf("sleeping for 2 sec\n");
		ret = read(fd, &buf, 10);
        	if (ret == -1) {
                	printf("Read from fd-%d failed\n", fd);
                	perror("Error is");
                	exit(0);
        	}
        	printf("%d bytes of data read from file and read data is %s\n", ret, buf);
		printf("sleeping again for 2 secs\n");
		exit(0);
	}
	printf("This is parent process [%d] and successfully created child process [%d]\n", getpid(), cpid);
	printf("printing 10 bytes from file\n");
	ret = read(fd, &buf, 10);
	if (ret == -1) {
		printf("Read from fd-%d failed\n", fd);
		perror("Error is");
		exit(0);
	}
	printf("%d bytes of data read from file and read data is %s\n", ret, buf);
	ret = wait(NULL);
	printf("Reading again from the file in parent process\n");
	if (ret == -1) {
		printf("wait system call failed\n");
		exit(0);
	}
	ret = read(fd, &buf, 10);
        if (ret == -1) {
                printf("Read from fd-%d failed\n", fd);
                perror("Error is");
                exit(0);
        }
        printf("%d bytes of data read from file and read data is %s\n", ret, buf);
	return 0;
}


/* Output:
 * [root@localhost process]# ./a.out
 * This is parent process and pid [3526]
 * This is parent process [3526] and successfully created child process [3527]
 * printing 10 bytes from file
 * 10 bytes of data read from file and read data is asdfgflkjh
 * This is child process and pid-3527
 * Parent process of this child is 3526
 * sleeping for 2 sec
 * 10 bytes of data read from file and read data is ghqwertrpo
 * sleeping again for 2 secs
 * Reading again from the file in parent process
 * 10 bytes of data read from file and read data is iuyuzxcvbv
 */
