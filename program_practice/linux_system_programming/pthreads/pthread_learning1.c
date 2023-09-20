#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * thread_handler (void * arg) {
    printf("Pid of the process is %d\n", getpid());
    char *args = (char *) arg;
    int count = 0;
    printf("thread function : called and received args is %s\n", args);
    printf("Thread id of the thread function is %d\n", pthread_self());
    printf("Sleeping for 15 seconds in thread function\n");
    sleep(15);
    printf("Exiting from thread function\n");
    pthread_exit(0);
}

int main(int argc, char * argv[]) {
    printf("Pid of the process is %d\n", getpid());
    pthread_t thread;
    int ret = 0;
    char *args = "Hello Buddy!";
    ret = pthread_create(&thread, NULL, thread_handler, (void *) args);
    printf("Return value of pthread_create is %d and created thread is %d\n", ret, thread);
    printf("Thread id of main thread is %d\n", pthread_self());
    if (ret != 0) {
        printf("Thread creation failed\n");
        perror("Error : ");
        exit(0);
    }
    printf("Sleeping for 5 seconds in main function\n");
    sleep(5);
    printf("Terminating main thread function\n");
    //exit(0); //Terminates all the associate threads as well
    pthread_exit(0); //Terminates only the main threas, another thread will still be running.
}

/* Output 1: Main thread will sleep for 3 seconds. So, before this another thread will be closed.
   labuser@Dev-VM4:~/pthread$ ./pthread_learning1
   Pid of the process is 20998
   Return value of pthread_create is 0 and created thread is 1238857472
   Pid of the process is 20998
   thread function : called and received args is Hello Buddy!
   Thread id of the thread function is 1238857472
   Sleeping for 2 seconds in thread function
   Thread id of main thread is 1247176512
   Sleeping for 3 seconds in main function
   Exiting from thread function
   Terminating main thread function
*/

/* Output 2: I have incremented the sleep in new thread as 15. Main thread will be sleeping for 3 secs.

   Main thread will be terminated well before the termination of the another thread.
   Since, I haven't used pthread_exit() for terminating main thread, along with main thread all other 
   associated threads will be terminated.

   labuser@Dev-VM4:~/pthread$ ./pthread_learning1
   Pid of the process is 21101
   Return value of pthread_create is 0 and created thread is -1800665344
   Thread id of main thread is -1792346304
   Sleeping for 3 seconds in main function
   Pid of the process is 21101
   thread function : called and received args is Hello Buddy!
   Thread id of the thread function is -1800665344
   Sleeping for 15 seconds in thread function
   Terminating main thread function

   labuser@Dev-VM4:~$ ps -ef | grep pthread_learning1
   labuser  21050 19598  0 05:34 pts/23   00:00:00 grep --color=auto pthread_learning1
   labuser@Dev-VM4:~$ ps -ef | grep pthread_learning1
   labuser  21065 19241  0 05:34 pts/5    00:00:00 ./pthread_learning1
   labuser  21075 19598  0 05:34 pts/23   00:00:00 grep --color=auto pthread_learning1
   labuser@Dev-VM4:~$ ps -ef | grep pthread_learning1
   labuser  21077 19598  0 05:34 pts/23   00:00:00 grep --color=auto pthread_learning1

*/

/* Output 3: Main thread will be terminated by pthread_exit() function. But still another thread will complete it's
   execution fully.
   labuser@Dev-VM4:~/pthread$ ./pthread_learning1
   Pid of the process is 21220
   Return value of pthread_create is 0 and created thread is -973060352
   Thread id of main thread is -964741312
   Sleeping for 3 seconds in main function
   Pid of the process is 21220
   thread function : called and received args is Hello Buddy!
   Thread id of the thread function is -973060352
   Sleeping for 15 seconds in thread function
   Terminating main thread function
   Exiting from thread function
*/
