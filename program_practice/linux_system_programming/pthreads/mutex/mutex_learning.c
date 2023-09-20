#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int gval = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * thread_handler () {
	int ret = 0;
	int count = 0;
	printf("Thread handler function invoked\n");
	ret = pthread_mutex_lock(&mutex);
	if (ret != 0) {
		perror("mutex lock failed and error is :");
	} else {
		printf("mutex lock successful and locked critical section\n");
	}
	printf("Count is %d\n", count);
	printf("Sleeping for 3 secs in critical section\n");  //Just for checking purpose
	sleep(3);
	for (count = 0; count <100; count++)
		gval += 1;
	printf("gval incremented and value is %d\n", gval);
	ret = pthread_mutex_unlock(&mutex);
	if (ret != 0) {
		perror("mutex unlock failed and error : ");
	} else {
		printf("mutex unlock successful and unlocked critical section\n");
	}
}

int main(int argc, char * argv[]) {
	pthread_t thread1;
	pthread_t thread2;
	int ret = 0;

	ret = pthread_create(&thread1, NULL, thread_handler, NULL);
	if (ret != 0) {
		printf("pthread creation failed\n");
		perror("Error is ");
		exit (-1);
	}
	ret = pthread_create (&thread2, NULL, thread_handler, NULL);
	if (ret != 0) {
		printf("pthread creation failed\n");
		perror ("Error is :");
		exit (-1);
	}

	ret = pthread_join(thread1, NULL);
	if (ret != 0)
		perror("pthread join failed and error is : ");
	ret = pthread_join(thread2, NULL);
	if (ret != 0)
		perror("pthread join failed and error is : ");

	printf("global value after both the thread completion is %d\n", gval);
	printf("Terminating main thread\n");
	exit(0);
}

/* Output :
 * [root@localhost mutex]# ./mutex_learning
 * Thread handler function invoked
 * mutex lock successful and locked critical section
 * Count is 0
 * Sleeping for 3 secs in critical section
 * Thread handler function invoked
 * 
 * 
 * gval incremented and value is 100
 * mutex unlock successful and unlocked critical section
 * mutex lock successful and locked critical section
 * Count is 0
 * Sleeping for 3 secs in critical section
 * 
 * 
 * gval incremented and value is 200
 * mutex unlock successful and unlocked critical section
 * global value after both the thread completion is 200
 * Terminating main thread
 */
