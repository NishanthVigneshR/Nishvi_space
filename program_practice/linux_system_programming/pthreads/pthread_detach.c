#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * thread_handler () {
    int res = 0;
    int count = 0;
    printf("Thread handler function invoked and pid is %d\n", getpid());
    res = pthread_detach(pthread_self());
    if (res != 0) {
        printf("pthread detach call failed\n");
        perror("");
    }
    for (count = 0;count <10; count++) {
        printf("sleeping 2 secs in thread function\n");
        sleep(2);
    }
    printf("Terminating another thread\n");
    pthread_exit(0);
}

int main() {
    printf("Main thread fn invoked and pid is %d\n", getpid());
    pthread_t thread;
    int ret = 0;
    ret = pthread_create (&thread, NULL,thread_handler, NULL);
    if (ret != 0) {
        printf("pthread_create system call failed\n");
        perror("");
    }
    printf("Terminating main thread\n");
    pthread_exit(0);
}

/* Output:
   labuser@Dev-VM4:~/pthread$ ./pthread_detach
   Main thread fn invoked and pid is 22509
   Terminating main thread
   Thread handler function invoked and pid is 22509
   sleeping 2 secs in thread function
   sleeping 2 secs in thread function
   sleeping 2 secs in thread function
   sleeping 2 secs in thread function
   sleeping 2 secs in thread function
   sleeping 2 secs in thread function
   sleeping 2 secs in thread function
   sleeping 2 secs in thread function
   sleeping 2 secs in thread function
   sleeping 2 secs in thread function
   Terminating another thread
*/
