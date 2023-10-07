#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	printf("This is process-1 and pid : %d\n", getpid());

	sem_t * sem = NULL;
	int ret = 0;
	int val = 0;

	sem = sem_open("/sem_demo", O_RDWR | O_CREAT, 0666, 1);
	// change the integer to no of dependent processes. But, except 1 all other processes will execute simultaneously.
	// As per my understanding, it's not working. Need to check this.

	if (sem == SEM_FAILED) {
		perror("Opening the semaphore failed : ");
		return 0;
	}

	ret = sem_getvalue (sem, &val);
	if (ret == -1) {
		perror("sem_getvalue call failed : ");
	}
	printf("current semaphore value : %d\n", val);

	ret = sem_wait(sem);
	if (ret == -1)
		perror("sem_wait system call failed\n");

	ret = sem_getvalue (sem, &val);
        if (ret == -1) {
                perror("sem_getvalue call failed : ");
        }
        printf("current semaphore value (after wait) : %d\n", val);

	/* critical section */
	printf("Sleeping for 15 secs\n");
	sleep(15);
	printf("log after 15 secs and exiting critical section\n");
	ret = sem_post(sem);
	if (ret == -1)
		perror("sem_post call failed : ");
	ret = sem_getvalue (sem, &val);
        if (ret == -1) {
                perror("sem_getvalue call failed : ");
        }
	printf("semaphore value after post : %d\n", val);
	printf("Terminating process-1\n");
	sem_close(sem);
	sem_unlink("/sem_demo");
	exit(0);
}

/* Output:
 *
 * [root@localhost Semaphores]# ./1_semaphore_M
This is process-1 and pid : 6219
current semaphore value : 1
current semaphore value (after wait) : 0
Sleeping for 15 secs
log after 15 secs and exiting critical section
semaphore value after post : 1
[root@localhost Semaphores]#
[root@localhost Semaphores]# cd /dev/shm/
[root@localhost shm]# ls
sem.sem_demo
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

