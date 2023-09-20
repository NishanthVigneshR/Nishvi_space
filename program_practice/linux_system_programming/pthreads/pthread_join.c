#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static void *thread_handler (void) {
    printf("Thread function invoked\n");
    int count = 0;
    for (count = 0;count < 5;count++) {
        printf("Sleeping thread func for 2 secs\n");
        sleep(2);
    }
    return (void *) 10;
}

int main() {
    pthread_t thread;
    int ret = 0;
    void *result = NULL;
    ret = pthread_create (&thread, NULL, thread_handler, NULL);
    if (ret != 0) {
        printf("pthread creation failed\n");
        perror("Error is ");
        exit(-1);
    }
    printf("Main thread : Calling join call\n");
    ret = pthread_join(thread, &result);
    if (ret != 0) {
        printf("pthread_join call failed\n");
        perror("Error :");
    }
    printf("Another Thread terminated and now going to terminate main thread\n");
    printf("result value is %d\n", (int *) result);
    exit(0);
}

/* Output :
   labuser@Dev-VM4:~/pthread$ ./pthread_join
   Main thread : Calling join call
   Thread function invoked
   Sleeping thread func for 2 secs
   Sleeping thread func for 2 secs
   Sleeping thread func for 2 secs
   Sleeping thread func for 2 secs
   Sleeping thread func for 2 secs
   Another Thread terminated and now going to terminate main thread
   result value is 10
*/
