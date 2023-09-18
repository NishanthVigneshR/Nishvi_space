#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int ret = 0;
	printf("This is program-1\n");
	char *args[] = {"Hi","This", "args", "provided", "by", "program-1", NULL};
	ret = execv("./exec_program2", args);
	if (ret == -1) {
		printf("Exec system call failed with below error\n");
		perror("Error is : ");
	}
	printf("This line won't be printed because execv() call will replace all the below codes\n");
}

/* Output 1: Program-1 output when program-2 is not compiled.
 * [root@localhost exec_library]# ./exec_program1
 * This is program-1
 * Exec system call failed with below error
 * Error is : : No such file or directory
 * This line won't be printed because execv() call will replace all the below codes
 */

/* Output 2: Program-2 alone compiled alone and got below output.
 * [root@localhost exec_library]# ./exec_program2
 * This is program-2
 * Program-2 :  argc is 1
 * arg 1 is ./exec_program2
 */

/*Output 3:
 * Below output observed when both the programs compiled and object files created.
 * [root@localhost exec_library]# ./exec_program1
 * This is program-1
 * This is program-2
 * Program-2 :  argc is 6
 * arg 1 is Hi
 * arg 2 is This
 * arg 3 is args
 * arg 4 is provided
 * arg 5 is by
 * arg 6 is program-1
 */

