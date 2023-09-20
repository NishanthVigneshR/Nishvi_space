/* In this program, I need two threads A and B. In thread A, I'll fill up the buffer string.
 * Once done, thread A should notify thread B. In thread B, I should print the filled buffer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

char buf[60] = {0};
int is_signal = 0;

void * thread_handlerA () {
	int ret = 0;
	printf("thread handler A function invoked\n");
	pthread_mutex_lock(&mutex);
	printf("mutex lock successful in thread handler A\n");
	sprintf(buf, "This is programming by using threads and condition variable");
	is_signal = 1;
	printf("Signaling to thread B for it's handling\n");
	ret = pthread_cond_signal(&cond_var);
	if (ret != 0)
		printf("signaling to condition variable failed and error : %d\n", ret);
	pthread_mutex_unlock(&mutex);
	printf("mutex unlock successful in thread handler A\n");
	pthread_exit(0);
}

void * thread_handlerB () {
	int ret = 0;
	printf("thread handler B function invoked\n");
	printf("Introduced 2 secs delay, so even if thread B handler executed first, thread A will lock the mutex first.\n");
	sleep(2);   // Introduced 2 secs delay, so even if thread B handler executed first, thread A will lock the mutex first.
	pthread_mutex_lock(&mutex);
	printf("mutex lock successful in thread handler B\n");
	if (is_signal == 0) {
		printf("Thread B invoked first, so will unlock mutex and wait for signal for condtion variable\n");
		ret = pthread_cond_wait(&cond_var, &mutex);
		if (ret != 0)
			printf("condition variable wait failed and error : %d\n", ret);
	}
	printf("The buffer filled in thread A is '%s'\n", buf);
	pthread_mutex_unlock(&mutex);
	printf("mutex unlock successful in thread handler B\n");
	pthread_exit(0);
}

int main(int argc, char * argv[]) {
	pthread_t thread1;
	pthread_t thread2;
	
	pthread_create(&thread1, NULL, thread_handlerA, NULL);
	pthread_create(&thread2, NULL, thread_handlerB, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Terminating main thread\n");
	exit(0);
}

/* Output 1: Thread B invoked first before Thread A.
 * [root@localhost conditional_variables]# ./con_variable
 * thread handler B function invoked
 * mutex lock successful in thread handler B
 * Thread B invoked first, so will unlock mutex and wait for signal for condtion variable
 * thread handler A function invoked
 * mutex lock successful in thread handler A
 * Signaling to thread B for it's handling
 * The buffer filled in thread A is 'This is programming by using threads and condition variable'
 * mutex unlock successful in thread handler B
 * mutex unlock successful in thread handler A
 * Terminating main thread
 */

/* Output 2: Thread B will be followed by Thread A.
 *
 * [root@localhost conditional_variables]# ./con_variable
 * thread handler B function invoked
 * Introduced 2 secs delay, so even if thread B handler executed first, thread A will lock the mutex first.
 * thread handler A function invoked
 * mutex lock successful in thread handler A
 * Signaling to thread B for it's handling
 * mutex unlock successful in thread handler A
 * mutex lock successful in thread handler B
 * The buffer filled in thread A is 'This is programming by using threads and condition variable'
 * mutex unlock successful in thread handler B
 * Terminating main thread
 */

