#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
        pid_t cpid = 0;
	pid_t cpid2 = 0;
        pid_t ret_pid = 0;
        int status = 0;

        printf("This is parent process and pid is %d\n", getpid());

        cpid = fork();

        if (cpid == -1) {
                printf("fork system call failed\n");
                exit(-1);
        }

        if (cpid == 0) {
                printf("This is Child process-1 and pid is %d\n", getpid());
                printf("Parent pid of this child process is %d\n", getppid());
		sleep(5);
                printf("Terminating child process-1\n");
                exit(1);
        }

        cpid2 = fork();
	if (cpid2 == -1) {
                printf("fork system call failed\n");
                exit(-1);
        }

        if (cpid2 == 0) {
                printf("This is Child process-2 and pid is %d\n", getpid());
                printf("Parent pid of this child process is %d\n", getppid());
		sleep(10);
                printf("Terminating child process-2\n");
                exit(1);
        }

	printf("This is parent process, successfully created child process-2 and it's pid is %d\n", cpid2);
        ret_pid = waitpid(cpid2, &status, 0);  // we will wait until cpid-2 terminated.
        printf("Parent process : child process[%d] terminated and status is %d\n", ret_pid, status);

        printf("This is parent process, successfully created child process and it's pid is %d\n", cpid);
        ret_pid = waitpid(cpid, &status, 0);  // we will wait until cpid terminated.
        printf("Parent process : child process[%d] terminated and status is %d\n", ret_pid, status);
        printf("Exiting parent process[%d]\n", getpid());
        exit(0);

	/* Output-1: (cpid2 will be terminated first, followd by cpid1).
	 * [root@localhost process]# ./waitpid_2_multiple_forks
	 * This is parent process and pid is 3447
	 * This is parent process, successfully created child process-2 and it's pid is 3449
	 * This is Child process-2 and pid is 3449
	 * Parent pid of this child process is 3447
	 * This is Child process-1 and pid is 3448
	 * Parent pid of this child process is 3447
	 * Terminating child process-2
	 * Parent process : child process[3449] terminated and status is 256
	 * This is parent process, successfully created child process and it's pid is 3448
	 * Terminating child process-1
	 * Parent process : child process[3448] terminated and status is 256
	 * Exiting parent process[3447]
	 */

	/* Output-2: first waitpid will chk for cpid2 termination. Second will chk for cpid1 termination.
	 * But, I am introducing delay in a way that, cpid1 will terminate first and then cpid2. Let's see..
	 *
	 * cpid1 will be zombie process until cpid2 gets terminated.
	 *
	 * Before Zombie:
	 * root        3536  0.0  0.1   2628   956 pts/1    S+   00:02   0:00 ./waitpid_2_multiple_forks
	 * root        3537  0.0  0.0   2628    96 pts/1    S+   00:02   0:00 ./waitpid_2_multiple_forks
	 * root        3538  0.0  0.0   2628    96 pts/1    S+   00:02   0:00 ./waitpid_2_multiple_forks
	 *
	 *
	 * After Zombie:
	 *
	 * root        3536  0.0  0.1   2628   956 pts/1    S+   00:02   0:00 ./waitpid_2_multiple_forks
	 * root        3537  0.0  0.0      0     0 pts/1    Z+   00:02   0:00 [waitpid_2_multi] <defunct>
	 * root        3538  0.0  0.0   2628    96 pts/1    S+   00:02   0:00 ./waitpid_2_multiple_forks
	 *
	 * Output:
	 * [root@localhost process]# ./waitpid_2_multiple_forks
	 * This is parent process and pid is 3536
	 * This is parent process, successfully created child process-2 and it's pid is 3538
	 * This is Child process-2 and pid is 3538
	 * Parent pid of this child process is 3536
	 * This is Child process-1 and pid is 3537
	 * Parent pid of this child process is 3536
	 * Terminating child process-1
	 * Terminating child process-2
	 * Parent process : child process[3538] terminated and status is 256
	 * This is parent process, successfully created child process and it's pid is 3537
	 * Parent process : child process[3537] terminated and status is 256
	 * Exiting parent process[3536]
	 */
}
