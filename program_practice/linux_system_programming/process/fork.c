#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int gval = 10;

int main(int argc , char *argv[]) {
	pid_t parent_id = 0;
	pid_t child_id = 0;
	int val = 5;

	printf("I'm parent process and my pid is %d\n", getpid());
	
	child_id = fork();  //pid in parent, 0 in child, -1 if failed
	if(child_id == -1) {
	    printf("Creating child process failed due to fork call failure\n");
	    return 0;
	}

	if (child_id != 0) {
	    printf("Parent process successfully created child process and child process pid is %d\n", child_id);
	    printf("Parent process : gval is %d and val is %d\n", gval, val);
	    printf("Parent process : Setting gval and val as 1\n");
	    gval = val = 1;
	    sleep(1);
	} else {
	    printf("This is child process and pid is %d\n", getpid());
	    printf("Child process : gval is %d and val is %d\n", gval, val);
	    val = val *4;
	    gval = gval * 5;
	    printf("I'm child process and my parent pid is %d\n", getppid());
	    printf("Modified variables , Child process : gval is %d and val is %d\n", gval, val);
	}
	printf("My pid is %d , gval is %d and val is %d\n", getpid(), gval, val);
	exit(0);

	/*Output :
	 * [root@localhost process]# ./basic_fork1
	 * I'm parent process and my pid is 3156
	 * Parent process successfully created child process and child process pid is 3157
	 * Parent process : gval is 10 and val is 5
	 * This is child process and pid is 3157
	 * Child process : gval is 10 and val is 5
	 * I'm child process and my parent pid is 3156
	 * Modified variables , Child process : gval is 50 and val is 20
	 * My pid is 3157 , gval is 50 and val is 20
	 * My pid is 3156 , gval is 10 and val is 5
	 */

	/* Output 2:
	 * [root@localhost process]# ./fork
	 * I'm parent process and my pid is 3217
	 * Parent process successfully created child process and child process pid is 3218
	 * Parent process : gval is 10 and val is 5
	 * Parent process : Setting gval and val as 1
	 * This is child process and pid is 3218
	 * Child process : gval is 10 and val is 5
	 * I'm child process and my parent pid is 3217
	 * Modified variables , Child process : gval is 50 and val is 20
	 * My pid is 3218 , gval is 50 and val is 20
	 * My pid is 3217 , gval is 1 and val is 1
	 */
}

