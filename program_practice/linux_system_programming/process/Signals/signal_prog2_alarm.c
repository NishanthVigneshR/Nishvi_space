/* In this program, I'll use alarm() call in main function.
 * Once alarm expires, it will return SIGALRM signal.
 * This signal will be handled in signal_handler.
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler (int signo) {
	printf("alarm signal handler function invoked\n");
#if 0
	if (signo == SIGALRM) {
		printf("SIGALRM signal received due to alarm() expiration. Terminating the process\n");
		exit(0);
	}

	/* Output :
	 * [root@localhost Signals]# ./a.out
	 * Pid of the process is 3314
	 * alarm for 4 seconds started
	 * SIGALRM signal received due to alarm() expiration. Terminating the process
	 */
#endif

#if 0
	if (signal(SIGALRM, SIG_IGN) == SIG_ERR) {
		printf("Signal system call failed while ignoring the SIG_ALRM signal\n");
		exit(-1);
	}

	/* Output: Since I ignored SIGALRM, further alarm() call becomes dummy and it won't be called again n again.
	 * Pid of the process is 3582
	 * alarm for 4 seconds started
	 * alarm signal handler function invoked
	 *
	 * ^C
	 */

#endif

#if 0
	if (signal(SIGALRM, SIG_DFL) == SIG_ERR) {
                printf("Signal system call failed while setting default operation for SIG_ALRM signal\n");
                exit(-1);
        }

	/* Output :
	 * [root@localhost Signals]# ./a.out
	 * Pid of the process is 3575
	 * alarm for 4 seconds started
	 * alarm signal handler function invoked
	 * Alarm clock
	 */
#endif
	alarm(4);
}

int main(int argc, char * argv[]) {
	printf("Pid of the process is %d\n", getpid());
	if (signal(SIGALRM, signal_handler) == SIG_ERR) {
		printf("signal system call failed\n");
		perror("Error is ");
		exit(-1);
	}
	printf("alarm for 4 seconds started\n");
	alarm(4);

	while(1);
}
