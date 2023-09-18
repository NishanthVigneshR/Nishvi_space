#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char * argv[]) {
	int ret = 0;
	pid_t cpid = 0;
	printf("This is program-1 and will call fork and exec system call\n");
	cpid = fork();
	if (cpid == 0) {
		printf("This is child process and pid is %d\n", getpid());
		printf("Parent process of this child process is %d\n", getppid());
		printf("Calling exec() call\n");
		char * args[] = {"Fork", "executed", "calling", "execv", NULL};
		ret =  execv ("./fork_exec_call_learning2", args);
		if (ret == -1) {
			printf("execv call failed with below error\n");
			perror("Error is : ");
		}
		exit(0);
	}
	printf("This is parent process and pid is %d, successfully created child process [%d]\n", getpid(), cpid);
	cpid = wait(NULL);
	printf("Child process terminated\n");
	printf("Exiting from parent process\n");
}

/* Output:
 * [root@localhost exec_library]# ./fork_exec_call_learning1
 * This is program-1 and will call fork and exec system call
 * This is parent process and pid is 3055, successfully created child process [3056]
 * This is child process and pid is 3056
 * Parent process of this child process is 3055
 * Calling exec() call
 * This is program-2 and my pid is 3056
 * Fork
 * executed
 * calling
 * execv
 * Child process terminated
 * Exiting from parent process
 */

