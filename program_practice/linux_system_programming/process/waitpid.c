#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	pid_t cpid = 0;
	pid_t ret_pid = 0;
	int status = 0;

	printf("This is parent process and pid is %d\n", getpid());

	cpid = fork();

	if (cpid == -1) {
		printf("fork system call failed\n");
		exit(-1);
	}

	if (cpid == 0) {
		printf("This is Child process and pid is %d\n", getpid());
		printf("Parent pid of this child process is %d\n", getppid());
		printf("Terminating child process\n");
		exit(1);
	}

	fork();
	printf("This is parent process, successfully created child process and it's pid is %d\n", cpid);
	ret_pid = waitpid(cpid, &status, 0);  // we will wait until cpid terminated.
	printf("Parent process : child process[%d] terminated and status is %d\n", ret_pid, status);
	printf("Exiting parent process[%d]\n", getpid());
	exit(0);

	/* Output:
	 * [root@localhost process]# ./waitpid
	 * This is parent process and pid is 3407
	 * This is parent process, successfully created child process and it's pid is 3408
	 * This is Child process and pid is 3408
	 * Parent pid of this child process is 3407
	 * Terminating child process
	 * Parent process : child process[3408] terminated and status is 256
	 * Exiting parent process[3407]
	 */
}
