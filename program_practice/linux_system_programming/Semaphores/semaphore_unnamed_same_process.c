#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
int gval = 0;

static void * threadfunc(void * args) {
	int ret = 0;
	int val = 0;
	ret = sem_getvalue(&sem, &val);
	if (ret != 0)
		printf("sem_getvalue failed\n");
	printf("current semaphore value : %d\n", val);

	printf("Invoking sem wait call\n");
	ret = sem_wait(&sem);
	if (ret != 0)
		printf("sem_wait failed\n");
	printf("sem_wait call unblocked\n");

	ret = sem_getvalue(&sem, &val);
        if (ret != 0)
                printf("sem_getvalue failed\n");
        printf("current semaphore value (after wait) : %d\n", val);

	/* critical section */
	//gval = gval + 1000;
	printf("before sleep\n");
	sleep(10);
	printf("after sleep\n");

	ret = sem_post(&sem);
	if (ret != 0)
		printf("sem_post failed\n");
	ret = sem_getvalue(&sem, &val);
        if (ret != 0)
                printf("sem_getvalue failed\n");
        printf("current semaphore value (after post) : %d\n", val);
}

int main() {
	pthread_t t1, t2, t3;
	int ret = 0;

	ret = sem_init(&sem, 0, 1);
	ret = pthread_create(&t1, NULL, threadfunc, NULL);
	if (ret != 0)
		printf("pthread create command failed for t1\n");
	ret = pthread_create(&t2, NULL, threadfunc, NULL);
	if (ret != 0)
		printf("pthread create failed for t2\n");
	ret = pthread_create(&t3, NULL, threadfunc, NULL);
	if (ret != 0)
		printf("pthread create failed for t3\n");
#if 1
	ret = pthread_join(t1, NULL);
	if (ret != 0)
		printf("pthread join for t1 failed\n");
	ret = pthread_join(t2, NULL);
	if (ret != 0)
		printf("pthread join for t2 failed\n");
	ret = pthread_join(t3, NULL);
	if (ret != 0)
		printf("pthread join for t3 failed\n");
#endif
	sem_destroy(&sem);
	printf("gval is %d\n", gval);
	printf("Terminating main thread\n");
	exit (0);
}

/* Output:
 * root@localhost Semaphores]# ./semaphore_unnamed_same_process
current semaphore value : 1
Invoking sem wait call
sem_wait call unblocked
current semaphore value (after wait) : 0
current semaphore value (after post) : 1
current semaphore value : 1
Invoking sem wait call
sem_wait call unblocked
current semaphore value (after wait) : 0
current semaphore value (after post) : 1
current semaphore value : 1
Invoking sem wait call
sem_wait call unblocked
current semaphore value (after wait) : 0
current semaphore value (after post) : 1
gval is 3000
Terminating main thread
[root@localhost Semaphores]#
[root@localhost Semaphores]# vim semaphore_unnamed_same_process.c
[root@localhost Semaphores]#
[root@localhost Semaphores]# gcc semaphore_unnamed_same_process.c -lpthread -o semaphore_unnamed_same_process
[root@localhost Semaphores]#
[root@localhost Semaphores]#
[root@localhost Semaphores]# ./semaphore_unnamed_same_process
current semaphore value : 1
Invoking sem wait call
sem_wait call unblocked
current semaphore value (after wait) : 0
before sleep
current semaphore value : 0
Invoking sem wait call
current semaphore value : 0
Invoking sem wait call
after sleep
current semaphore value (after post) : 1
sem_wait call unblocked
current semaphore value (after wait) : 0
before sleep
after sleep
current semaphore value (after post) : 1
sem_wait call unblocked
current semaphore value (after wait) : 0
before sleep
after sleep
current semaphore value (after post) : 1
gval is 0
Terminating main thread
*/
