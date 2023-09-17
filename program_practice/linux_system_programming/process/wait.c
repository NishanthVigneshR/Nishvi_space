#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	pid_t cpid = 0;
	pid_t ret_pid = 0;
	int status = 0;

	printf("This is parent Process and pid is %d\n", getpid());
	cpid = fork();
	if (cpid == -1) {
		printf("fork system call failed\n");
		exit(0);
	}

	if (cpid == 0) {
		printf("This is child process and pid is %d\n", getpid());
		printf("Parent process pid of this child process is %d\n", getppid());
		sleep(10);   // To check child process due to kill, introduced sleep. In this delay, I'll kill child pid.
		printf("Terminating child process\n");
		exit(1);
	}
	
	printf("This is parent process, I have created child process successfully and it's pid is %d\n", cpid);
	ret_pid = wait(&status);
	if (ret_pid == -1) {
		printf("wait system call failed\n");
		exit(0);
	}
	printf("Parent process: Child process [%d] terminated and status is %d\n", ret_pid, status);
	printf("Parent process: exiting\n");
	exit(0);

	/* Output:
	 * [root@localhost process]# ./wait
	 * This is parent Process and pid is 3218
	 * This is parent process, I have created child process successfully and it's pid is 3219
	 * This is child process and pid is 3219
	 * Parent process pid of this child process is 3218
	 * Terminating child process
	 * Parent process: Child process [3219] terminated and status is 256
	 * Parent process: exiting
	 */

	/* Output:
	 * [root@localhost process]# ./wait
	 * This is parent Process and pid is 3295
	 * This is parent process, I have created child process successfully and it's pid is 3296
	 * This is child process and pid is 3296
	 * Parent process pid of this child process is 3295
	 * Parent process: Child process [3296] terminated and status is 9
	 * Parent process: exiting[root@localhost process]# ./wait
	 * This is parent Process and pid is 3297
	 * This is parent process, I have created child process successfully and it's pid is 3298
	 * This is child process and pid is 3298
	 * Parent process pid of this child process is 3297
	 * Parent process: Child process [3298] terminated and status is 136
	 * Parent process: exiting
	 *
	 * [root@localhost process]# kill -9 3296
	 * [root@localhost process]# kill -8 3298
	 */

	/* I have commented fork and child part of code. Checked how wait will respond if there is no child process.
	 * wait call will fail and returns -1.
	 * Output:
	 * This is parent Process and pid is 3365
	 * This is parent process, I have created child process successfully and it's pid is 0
	 * wait system call failed
	 */
}
