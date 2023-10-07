#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
	printf("This is process-2 and pid - %d\n", getpid());

	sem_t * sem = NULL;
	int ret = 0;
	int val = 0;

	sem = sem_open ("/sem_demo", O_RDWR);  // We need to peform both read n write (post n wait).
	
	if (sem == SEM_FAILED) {
		perror("Sem open failed and error : ");
		return 0;
	}
	printf("semaphore opened\n");

	ret = sem_getvalue (sem, &val);
	if (ret == -1) {
		perror("sem_getvalue failed\n");
	}
	printf("Current semaphore value : %d\n", val);

	printf("Calling sem_wait function\n");
	ret = sem_wait(sem);
	if (ret == -1)
		perror("sem_wait call failed\n");

	printf("Sem wait unblocked\n");

	ret = sem_getvalue (sem, &val);
	if (ret == -1)
		perror("Sem getvalue after wait call failed\n");
	printf("current semaphore value : %d\n", val);

	/* Critical section */
	printf("Sleeping for 10 secs\n");
	sleep(10);
	printf("log after 10 secs sleep\n");

	//sem_post(sem); // will inform other processes
	printf("Terminating process-2\n");
	sem_close(sem);
	return 0;	
}

/* Output :
 * [root@localhost Semaphores]# ./2_semaphore_named_S
This is process-2 and pid - 6866
semaphore opened
Current semaphore value : 0
Calling sem_wait function
Sem wait unblocked
current semaphore value : 0
Sleeping for 10 secs
log after 10 secs sleep
Terminating process-2
*/

/* Total Output:
 *
 * [root@localhost Semaphores]# ./1_semaphore_M
This is process-1 and pid : 6865
current semaphore value : 1
current semaphore value (after wait) : 0
Sleeping for 15 secs
log after 15 secs and exiting critical section
semaphore value after post : 1
Terminating process-1

 *
 * [root@localhost Semaphores]# ./2_semaphore_named_S
This is process-2 and pid - 6866
semaphore opened
Current semaphore value : 0
Calling sem_wait function
Sem wait unblocked
current semaphore value : 0
Sleeping for 10 secs
log after 10 secs sleep
Terminating process-2
*
* [root@localhost shm]# ls
sem.sem_demo
[root@localhost shm]#
[root@localhost shm]# ls
[root@localhost shm]# ls
*/
