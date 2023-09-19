/* In this program, child process related code is present.
 * child process will be terminated once it receives SIGUSR1 from parent process.
 * It will send SIGUSR2 to parent process for terminating it
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void signal_handler (int signo) {
	if (signo == SIGUSR1) {
		printf("Received SIGUSR1 from parent process and terminating child process [%d]\n", getpid());
		printf("Sending SIGUSR2 to parent process for termination\n");
        	sleep(5);
        	kill(getppid(), SIGUSR2);
		exit(0);
	}
}

int main(int argc, char * argv[]) {
	printf("This is child process and pid is %d\n", getpid());
	int count = 0;
	int ret = 0;
	if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
		printf("signal system call failed\n");
		exit(-1);
	}
	for (count = 0;count < argc; count++) {
		printf("argv-%d is %s\n", count, argv[count]);
	}
	while(1) {
		printf("child process sleeping for 2 secs\n");
		sleep(2);
	}
}


