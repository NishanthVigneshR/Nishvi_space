#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

//sighandler_t signal_handler (int signo) {
void signal_handler (int signo) {
	if (signo == SIGINT) {
		printf("SIGINT signal received\n");
	} else if (signo == SIGKILL) {
		printf("SIGKILL signal received\n");
	} else if (signo == SIGTERM) {
		printf("SIGTERM signal received\n");
	}
	exit(0);  // Initially missed exit() call. So, process not terminated
}

int main(int argc, char * argv[]) {
	int *ret = NULL;
	printf("Pid of this process is %d\n", getpid());

#if 0
	/* Handling the signal with signal_handler function */

	ret = (int *) signal(SIGINT, signal_handler);
	printf("SIGINT handling added in signal_handler and ret is %d\n", ret);
	
	ret = (int *)signal(SIGTERM, signal_handler);
        printf("SIGTERM handling added in signal_handler and ret is %d\n", ret);
	
	/*ret = (int *) signal(SIGKILL, signal_handler);
        printf("SIGKILL handling added in signal_handler and ret is %d\n", ret);
        perror ("Error is :");

        Getting -1 return code. So,commenting it for now.
        Error : SIGKILL handling added in signal_handler and ret is -1
        Error is :: Invalid argument
        */
#endif

#if 0
	/* Ignoring the signals */

	if (signal(SIGINT, SIG_IGN) == SIG_ERR) {
		printf("Assigned ignore option for SIGINT and signal call failed\n");
		perror("Error is ");
		exit(-1);
	}

	if (signal(SIGTERM, SIG_IGN) == SIG_ERR) {
                printf("Assigned ignore option for SIGTERM and signal call failed\n");
                perror("Error is ");
                exit(-1);
        }
#endif

#if 1
	/* Default action of the signal */
	if (signal(SIGINT, SIG_DFL) == SIG_ERR) {
                printf("Assigned default option for SIGINT and signal call failed\n");
                perror("Error is ");
                exit(-1);
        }

        if (signal(SIGTERM, SIG_DFL) == SIG_ERR) {
                printf("Assigned default option for SIGTERM and signal call failed\n");
                perror("Error is ");
                exit(-1);
        }
#endif

	while (1) {
		printf("This is infinite loop and sleeping for every 5 secs\n");
		sleep(3);
	}	
}

/* Output 1:  Both SIGINT & SIGTERM handling will be done by handler function.
 * [root@localhost Signals]# ./signal_prog1
Pid of this process is 3295
SIGINT handling added in signal_handler and ret is 0
SIGKILL handling added in signal_handler and ret is -1
SIGTERM handling added in signal_handler and ret is 0
This is infinite loop and sleeping for every 5 secs
This is infinite loop and sleeping for every 5 secs
^CSIGINT signal received
[1]+  Killed                  ./signal_prog1
[root@localhost Signals]# ./signal_prog1
Pid of this process is 3296
SIGINT handling added in signal_handler and ret is 0
SIGKILL handling added in signal_handler and ret is -1
SIGTERM handling added in signal_handler and ret is 0
This is infinite loop and sleeping for every 5 secs
This is infinite loop and sleeping for every 5 secs
This is infinite loop and sleeping for every 5 secs
[root@localhost Signals]# kill -15 3296
SIGTERM signal received
*/

/* Output-2: I have mentioned SIG_IGN (Ignore Handling) for both SIGTERM and SIGINT. Process haven't terminated due to ignore.
 * [root@localhost Signals]# ./a.out
 * Pid of this process is 2980
 * This is infinite loop and sleeping for every 5 secs
 * This is infinite loop and sleeping for every 5 secs
 * ^CThis is infinite loop and sleeping for every 5 secs ---> Given ctrl+c but still process runs.
 * This is infinite loop and sleeping for every 5 secs
 * This is infinite loop and sleeping for every 5 secs
 */

/* Output -3 : Default action will be performed to the signals.
 * [root@localhost Signals]# ./signal_prog1
 * Pid of this process is 3093
 * This is infinite loop and sleeping for every 5 secs
 * This is infinite loop and sleeping for every 5 secs
 * ^C
 * [root@localhost Signals]# ./signal_prog1
 * Pid of this process is 3094
 * This is infinite loop and sleeping for every 5 secs
 * This is infinite loop and sleeping for every 5 secs
 * This is infinite loop and sleeping for every 5 secs
 * This is infinite loop and sleeping for every 5 secs
 * Terminated
 */

