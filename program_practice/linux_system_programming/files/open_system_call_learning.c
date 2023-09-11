#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main() {
	int open_fd = 0;
	open_fd = open ("demoopenfile", O_RDONLY | O_CREAT, S_IRWXU|S_IRGRP|S_IRWXO);
	if (open_fd < 0) {
		printf("Open system call failed\n");
		perror("\nError is :");
		return 0;
	}
	printf("\nNew file opened successfully and it's fd : %d\n", open_fd);

	/* Output : Mentioned file is not present. So, I got below error. Used only O_RDONLY flag.
	 * Open system call failed
	 * Error is :: No such file or directory
	 *
	 * Now I created the file which mentioned in open system call. I got below output now.
	 *
	 * [root@localhost files]# ./open_system_call_learning
         * New file opened successfully and it's fd : 3
	 */

	/* We can avoid it by using O_CREAT flag. If file is not present, by using O_CREAT flag we can create that file */
}
