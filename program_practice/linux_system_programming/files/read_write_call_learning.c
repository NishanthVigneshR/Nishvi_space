#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int open_fd = 0;
	int write_ret = 0;
	int read_ret = 0;
	char read_buf[30] = {0};
	char buf[] = "Hello Buddy ! All the best";
	//open_fd = open("demofile2", O_WRONLY | O_CREAT | O_EXCL, 0777);
	open_fd = open("demofile2", O_RDWR | O_CREAT | O_EXCL, 0777);
	if (open_fd < 0) {
		printf("opening the file failed\n");
		return 0;
	}
	printf("File opened successfully and it's fd : %d\n", open_fd);
	write_ret = write(open_fd, "hello dude ! all the very best.\n", 32);
	if (write_ret == -1) {
		printf("Write call failed with below error\n");
		perror("Error :");
		//return 0;
		/* I provided flag as read-only, so write failed and got below error
		 * open("demofile2", O_RDONLY | O_CREAT, 0777);
		 * Output:
		 * root@localhost files]# ./read_write_call_learning
		 * File opened successfully and it's fd : 3
		 * Write call failed with below error
		 * Error :: Bad file descriptor 
		 */
	}
	printf("Successfully written %d bytes of data to the file\n", write_ret);
	/* Write system call is successful and got below output:
	 * [root@localhost files]# ./read_write_call_learning
	 * File opened successfully and it's fd : 3
	 * Successfully written 26 bytes of data to the file
	 * [root@localhost files]#
	 * [root@localhost files]#
	 * [root@localhost files]# cat demofile2
	 * Hello Buddy ! All the best
	 */

	/* Now, I'm going to write to the same file. Only O_RDWR and O_CREAT flag is defined. */
	write_ret = write(open_fd, "Thanks buddy!\n", 15);
	if (write_ret == -1) {
                printf("Write call failed with below error\n");
                perror("Error :");
                //return 0;
	}
	printf("Successfully written %d bytes of data to the file\n", write_ret);

	/* New data appended with existing data.
	 * Output:
	 * [root@localhost files]# cat demofile2
	 * Hello Buddy ! All the bestThanks buddy!
	 */

	read_ret = read(open_fd, read_buf, 10);
	if (read_ret == -1) {
		printf("read system call failed and got below error\n");
		perror("Error : ");
		//return 0;
	} else if (read_ret == 0) {
		printf("Both read n write uses same offset pointer, so read will be at EOF n 0 bytes will be read\n");
		perror("");
	}
	printf("Read %d bytes of data and read_data is %s\n", read_ret, read_buf);

	/* By using O_WRONLY flag, we can write to file.
	 * O_TRUNC flag removes existing data and fills the file freshly
	 * O_APPEND flag adds the data from EOF. It retains existing data.
	 * When I use O_RDWR flag, read system call also not working as expected.
	 * But, with O_RDONLY flag, read system call works fine. Need to check it.
	 */

	int ret = lseek (open_fd, 0, SEEK_SET);
	printf("Read failed, so seeking the file to beginning n lseek ret - %d\n", ret);

	read_ret =  read(open_fd, read_buf, 15);
	if (read_ret == -1) {
		 printf("read system call failed and got below error\n");
                 perror("Error : ");
                 //return 0;
	}
	printf("[After seek] Read %d bytes of data and read_data is %s\n", read_ret, read_buf);

	/* Output:
	 * [root@localhost files]# ./a.out
	 * File opened successfully and it's fd : 3
	 * Successfully written 32 bytes of data to the file
	 * Successfully written 15 bytes of data to the file
	 * Read 0 bytes of data and read_data is
	 * Read failed, so seeking the file to beginning n lseek ret - 0
	 * [After seek] Read 15 bytes of data and read_data is hello dude ! al
	 */


	/* I have used O_EXCL flag in open call. Now, the file can be edited only first time.
	 * If we try to edit second time, we will get error. 
	 * Output :
	 * [root@localhost files]# cat demofile2
	 * hello dude ! all the very best.
	 * Thanks buddy!
	 * [root@localhost files]# ./a.out
	 * opening the file failed
	 */

	/* Output after lseek again.
	 * [root@localhost files]# ./a.out
	 * File opened successfully and it's fd : 3
         * Successfully written 32 bytes of data to the file
         * Successfully written 15 bytes of data to the file
         * Both read n write uses same offset pointer, so read will be at EOF n 0 bytes will be read
         * Success
         * Read 0 bytes of data and read_data is
         * Read failed, so seeking the file to beginning n lseek ret - 0
         * [After seek] Read 15 bytes of data and read_data is hello dude ! al
	 */
}
