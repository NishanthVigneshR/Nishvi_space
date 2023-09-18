/* execvpe() system call is used to modify the environment of the process.
 * In program1, I will provide environment variables as input for program-2.
 * In program-2, I'll print environment params of the current process.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int ret = 0;
	printf("This is program-1 and calling execvpe call\n");
	char * envp[] = {"Var1=Ooty","Var2=Kozhikode","Var3=Palani", NULL};
	ret = execvpe ("./env_exec_program2", NULL, envp);
	if (ret == -1) {
		printf("execvpe system call failed\n");
		perror("Error is : ");
	}
	printf("Only on failure of execvpe call, this line will be printed\n");
}

/* Output:
 * [root@localhost exec_library]# ./env_exec_program1
 * This is program-1 and calling execvpe call
 * Printing env variables of the process
 * Var1=Ooty
 * Var2=Kozhikode
 * Var3=Palani
 */
