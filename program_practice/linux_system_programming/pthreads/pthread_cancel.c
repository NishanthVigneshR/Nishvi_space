#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * thread_handler(void) {
    printf("Thread function invoked and looping infinitely\n");
    int count = 0;
    for (count = 0;count < 10;count++) {
        printf("Thread function : sleeping for 2 secs\n");
        sleep(2);
    }
    printf("Terminating thread function\n");
    pthread_exit(0);
}

int main() {
    pthread_t thread;
    int ret = 0;

    ret = pthread_create (&thread, NULL, thread_handler, NULL);
    if (ret != 0) {
        printf("pthread create call failed\n");
        perror ("");
    }
    printf("Sleeping 8 secs in main thread\n");
    sleep(8);

    printf("Main thread : Calling pthread cancel function and terminating other thread\n");
    pthread_cancel(thread);

    printf("Terminating main thread\n");
    pthread_exit(0);
}

/* Output:
   labuser@Dev-VM4:~/pthread$ ./pthread_cancel
   Sleeping 8 secs in main thread
   Thread function invoked and looping infinitely
   Thread function : sleeping for 2 secs
   Thread function : sleeping for 2 secs
   Thread function : sleeping for 2 secs
   Thread function : sleeping for 2 secs
   Main thread : Calling pthread cancel function and terminating other thread
   Terminating main thread
*/
