/* In this program, I will invoke parent process. By using fork and exec(), I'll invoke child process.
 * I'll send SIGUSR1 to child process and will expect it to terminate the child process.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler (int signo) {
	if (signo == SIGUSR2) {
		printf("Parent process receives SIGUSR2 and terminating parent process [%d]\n", getpid());
		exit(0);
	}
}

int main(int argc, char * argv[]) {
	pid_t cpid = 0;
	printf("This is parent process and my pid is %d\n", getpid());
	cpid = fork();
	if (cpid == -1) {
		printf("fork system call failed\n");
		perror("Error is ");
		exit(-1);
	}
	if (cpid == 0) {
		printf("This is child process and pid is %d\n", getpid());
		printf("Parent process of this child process is %d\n", getppid());
		char * args[] = {"Parent","will", "send","SIGUSR1","To","Terminate","child", NULL};
		execv("./signal_SIGUSR_child", args);
	}
	printf("Parent process successfully created child process [%d]\n", cpid);
	if (signal(SIGUSR2, signal_handler) == SIG_ERR) {
		printf("signal system call failed\n");
		exit(-1);
	}
	sleep(7);
	printf("Sending SIGUSR1 to child process for termination\n");
	kill(cpid, SIGUSR1);
	wait(NULL);
}

/* Output:
[root@localhost Signals]# ./signal_SIGUSR_parent
This is parent process and my pid is 3368
Parent process successfully created child process [3369]
This is child process and pid is 3369
Parent process of this child process is 3368
This is child process and pid is 3369
argv-0 is Parent
argv-1 is will
argv-2 is send
argv-3 is SIGUSR1
argv-4 is To
argv-5 is Terminate
argv-6 is child
child process sleeping for 2 secs
child process sleeping for 2 secs
child process sleeping for 2 secs
child process sleeping for 2 secs
Sending SIGUSR1 to child process for termination
Received SIGUSR1 from parent process and terminating child process [3369]
Sending SIGUSR2 to parent process for termination
Parent process receives SIGUSR2 and terminating parent process [3368]
*/
