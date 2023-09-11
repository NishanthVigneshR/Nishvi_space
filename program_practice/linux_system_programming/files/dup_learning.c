#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int open_fd = 0;
	int new_fd = 0;
	int ret = 0;
	char buf[20] = {0};

	open_fd = open("demofile4", O_RDWR);

	if (open_fd == -1) {
	    printf("open system call failed\n");
	    perror("Error : ");
	    return 0;
	}

	printf("file opened successfully anf it's fd : %d\n", open_fd);
	new_fd = dup(open_fd);
	if (new_fd == -1) {
		printf("dup system call failed\n");
		perror("Error : ");
		return 0;
	}

	printf("dup system call success and new fd is %d\n", new_fd);

	/* After duplicating the oldfd successfully, I got below output.
	 * [root@localhost files]# ./a.out
	 * file opened successfully anf it's fd : 3
	 * dup system call success and new fd is 4
	 */

	/* Now, modify the offset pointer and check how oldfd and newfd working.
	 * Both will be sharing same offset pointer.
	 */
	ret = read(open_fd, buf, 12); //Hello buddy!
	printf("Read call executed and %d bytes read and data : %s\n", ret, buf);

	ret = read(new_fd, buf, 12);
	printf("Read call executed and %d bytes read and data : %s\n", ret, buf);

	/* Output :
	 * [root@localhost files]# ./a.out
	 * file opened successfully anf it's fd : 3
	 * dup system call success and new fd is 4
	 * Read call executed and 12 bytes read and data : Hello Buddy!
	 * Read call executed and 12 bytes read and data :  This is dem
	 */

	/* now, lets move to dup2 */

	ret = dup2(open_fd, 1);
       	/* Here, 1 was pointing to stdout. Now, 1 will point to file which pointed by open_fd pointer.
	 * So, further printf statements will be executed in the file and not in screen.
	 */

	if (ret == -1) {
		printf("dup2 system call failed\n");
		perror("Error : ");
		return 0;
	}
	lseek (open_fd, 0, SEEK_END);
	printf("dup2 call success and ret : %d\n", ret);

	/* Final Output :
	 * [root@localhost files]# ./a.out
	 * file opened successfully anf it's fd : 3
	 * dup system call success and new fd is 4
	 * Read call executed and 12 bytes read and data : Hello Buddy!
	 * Read call executed and 12 bytes read and data :  This is dem
	 * [root@localhost files]#
	 * [root@localhost files]# cat demofile4
	 * Hello Buddy! This is demo file which I am using for learning dup system calls.
	 * dup2 call success and ret : 1
	 */
}
