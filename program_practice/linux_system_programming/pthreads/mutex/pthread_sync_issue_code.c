#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int gval = 0;

void * thread_handlerA() {
	printf("Thread handler for thread A invoked\n");
	for (int i = 0;i <1000;i++) {
		gval += 1;
	}
	printf("ThreadA : gval after increment is %d\n", gval);
	printf("Terminating thread A handler\n");
	pthread_exit(0);
}

void * thread_handlerB() {
        printf("Thread handler for thread B invoked\n");
        for (int i = 0;i <1000;i++) {
                gval += 1;
        }
	printf("ThreadB : gval after increment is %d\n", gval);
        printf("Terminating thread B handler\n");
        pthread_exit(0);
}

int main() {
	pthread_t thread1;
	pthread_t thread2;
	int ret = 0;

	ret = pthread_create (&thread1, NULL, thread_handlerA, NULL);
	if (ret != 0) {
		printf("pthread creation failed\n");
		perror("Error :");
		exit(-1);
	}
	ret =  pthread_create (&thread2, NULL, thread_handlerB, NULL);
	if (ret != 0)  {
		printf("pthread creation failed\n");
		perror("Error :");
		exit(-1);
	}
	ret =  pthread_join(thread1, NULL);
	if (ret != 0) {
		printf("pthread_join failed\n");
		perror("Error :");
	}

	ret =  pthread_join(thread2, NULL);
        if (ret != 0) {
                printf("pthread_join failed\n");
                perror("Error :");
        }
	printf("gval after all the join call is %d\n", gval);

	printf("Terminating main thread\n");
	pthread_exit(0);
}

/* Output :
 * Here, I have incremented global integer variable in two threads.
 * We will get undefined behaviour. But, in the code written I'm getting correct Output.
 * But, still it's not the correct way to do. At any time, we will end up in sync issue.
 * [root@localhost mutex]# ./pthread_sync_issue_code
 * Thread handler for thread B invoked
 * ThreadB : gval after increment is 1000
 * Terminating thread B handler
 * Thread handler for thread A invoked
 * ThreadA : gval after increment is 2000
 * Terminating thread A handler
 * gval after all the join call is 2000
 */
