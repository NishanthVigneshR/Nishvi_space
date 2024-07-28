#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int open_fd = 0;
	int ret = 0;
	char buf[20] = {0};

	open_fd = open("demofile3", O_RDONLY);

	/*Content of demofile3: I have created demofile3 for learning lseek system call */

	ret = read(open_fd, buf, 10);
	/* Reading 10 bytes of the file. Since, this is the first read call. 1st 10 byes will be read.
	 * Output will be "I have cre".
	 */
	buf[10] = '\0';
	printf("\n Output after first read call : %d : %s\n", ret, buf);

	ret = read(open_fd, buf, 5);
	buf[5] = '\0';
	/* Now, I'm using read call again. Offset pointer will be at 11th byte. Now, data from 11-16 bytes will be printed.
	 * Output will be "ated ".
	 */
	printf("\n Output after first read call : %d : %s\n", ret, buf);

	ret = lseek(open_fd, 3, SEEK_CUR);
	printf("Return value of lseek is %d\n", ret);
	/* Offset pointer is at 17th byte. By using lseek, I have moved offset pointer to 3 bytes forward
	 * from current position (SEEK_CUR).
	 */
	ret = read(open_fd, buf, 6);
        buf[6] = '\0';
	printf("\n Output after next read call : %d : %s\n", ret, buf); // Output : ofile3

	ret = lseek(open_fd, 0, SEEK_END); // Moved offset pointer to EOF.
	printf("Return value of lseek (SEEK_END) is %d\n", ret);

	ret = read(open_fd, buf, 3);  // I think we moved to offset to EOF. So, read will return 0.
	if (ret == 0) {
		printf("EOF reached and read call returned 0\n");
	}

	ret = lseek (open_fd, 0, SEEK_SET);  // Moved offset pointer to start of the file.
	printf("Return value of lseek (SEEK_END) is %d\n", ret);

        ret = read(open_fd, buf, 14);  // I think we moved to offset to EOF. So, read will return 0.
	printf("\n Output after next read call : %d : %s\n", ret, buf);


	/* Final Output :
	 * [root@localhost files]# ./a.out
	 * Output after first read call : 10 : I have cre
	 *  Output after first read call : 5 : ated
	 *  Return value of lseek is 18
	 *   Output after next read call : 6 : ofile3
	 *   Return value of lseek (SEEK_END) is 56
	 *   EOF reached and read call returned 0
	 *   Return value of lseek (SEEK_END) is 0
	 *    Output after next read call : 14 : I have created
	 */

	// Noticed that we can specify the offset with negative integers as well. Let's try it out.
	
	ret = lseek(open_fd, 0, SEEK_SET); // fd moves to start
	ret = read(open_fd, buf, 5);
	buf[5] = '\0';
	printf("After moving to beginning read 5 bytes, %s\n", buf);

	ret = lseek(open_fd, 10, SEEK_SET);
	ret = read(open_fd, buf, 5);
	buf[5] = '\0';
        printf("After moving to beginning n then 10 bytes offset, read 5 bytes, %s\n", buf);

	ret = lseek(open_fd, -4, SEEK_CUR); //From Offset 15, going backwards 4 times.
	ret = read(open_fd, buf, 5);
	buf[5] = '\0';
	printf("Used -4 from seek_curr n buf - %s\n", buf);

	ret = lseek(open_fd, -10, SEEK_END);
	ret = read(open_fd, buf, 5);
	buf[5] = '\0';
	printf("Moved to EOF n then decremented offset by 10, read 5 bytes n buf - %s\n", buf);
#if 0
	/* Output */
	[root@localhost files]# ./a.out

		Output after first read call : 10 : NishanthVi

			Output after first read call : 5 : gnesh
			Return value of lseek is 18

			Output after next read call : 6 : pgemin
			Return value of lseek (SEEK_END) is 37
			EOF reached and read call returned 0
			Return value of lseek (SEEK_END) is 0

			Output after next read call : 14 : NishanthVignes
			After moving to beginning read 5 bytes, Nisha
			After moving to beginning n then 10 bytes offset, read 5 bytes, gnesh
			Used -4 from seek_curr n buf - neshR
			Moved to EOF n then decremented offset by 10, read 5 bytes n buf - ginee

#endif
}
