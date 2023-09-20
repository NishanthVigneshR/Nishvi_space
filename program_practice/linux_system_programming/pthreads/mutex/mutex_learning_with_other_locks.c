#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * thread_handler() {
	int ret = 0;
	printf("Thread handler function invoked\n");
	//ret = pthread_mutex_trylock(&mutex);
#if 0
	struct timespec timeoutTime;
	clock_gettime(CLOCK_REALTIME, &timeoutTime);
        timeoutTime.tv_sec += 3;
	ret = pthread_mutex_timedlock(&mutex, &timeoutTime);
#endif
	if (ret != 0) {
		printf("mutex lock failed and error number : %d\n", ret);
		pthread_exit(0);
	} else {
		printf("mutex lock successful\n");
	}
	printf("sleeping for 5 secs in critical section\n");
	sleep(5);
	ret = pthread_mutex_unlock(&mutex);
	if (ret != 0) {
		perror("mutex unlock failed and error : ");
	} else {
		printf("mutex unlock successful\n");
	}
	printf("Terminating thread handler\n");
	pthread_exit(0);
}

int main() {
	pthread_t thread1;
	pthread_t thread2;
	int ret = 0;

	ret =  pthread_create(&thread1, NULL, thread_handler, NULL);
	if (ret != 0) {
		perror("Failed to create pthread and error : ");
		exit(-1);
	}
	ret = pthread_create(&thread2, NULL, thread_handler, NULL);
	if (ret != 0) {
		perror ("Failed to create pthread and error : ");
		exit(-1);
	}

	ret = pthread_join(thread1, NULL);
	if (ret != 0)
		perror("pthread join call failed and error : ");
	ret =  pthread_join(thread2, NULL);
	if (ret != 0)
		perror("pthread join call failed and error : ");

	printf("Terminating main pthread\n");
	pthread_exit(0);
}

/* Output : when used pthread_mutex_trylock() call.
 * [root@localhost mutex]# ./mutex_learning_with_other_locks
 * Thread handler function invoked
 * mutex lock successful
 * sleeping for 5 secs in critical section
 * Thread handler function invoked
 * mutex lock failed and error number : 16
 * Success
 * mutex unlock successful
 * Terminating thread handler
 * Terminating main pthread
 */

/* Output : when pthread_mutex_timedlock() call used. From real world time, it will wait for mentioned time.
 * Output 1 : thread will become owner within expiration time.
 *
 * [root@localhost mutex]# ./mutex_learning_with_other_locks
 * Thread handler function invoked
 * mutex lock successful
 * sleeping for 5 secs in critical section
 * Thread handler function invoked
 * mutex lock failed and error number : 0
 * mutex unlock successful
 * Terminating thread handler
 * Terminating main pthread
 *
 *---------------------------------------------
 *
 * Output 2 : when expiration time expires but still mutex is locked by another client.
 *
 * [root@localhost mutex]# ./mutex_learning_with_other_locks
 * Thread handler function invoked
 * mutex lock successful
 * sleeping for 5 secs in critical section
 * Thread handler function invoked
 * mutex lock failed and error number : 110
 * mutex unlock successful
 * Terminating thread handler
 * Terminating main pthread
 */

