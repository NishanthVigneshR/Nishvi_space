#include <stdio.h>

int main() {
	int var = 0;
	int zeroes_count = 0;
	int i = 0;
	int size = (sizeof(int) * 8);

	printf("Enter the number\n");
	scanf("%d", &var);

	for (i = 0;i < size;i++) {
	//for (i = size -1; i >= 0; i--) {
		int mask = size -1 -i;
		if (var >> mask & 1) {
			break;
		}
		zeroes_count++;
	}
	printf("No of leading zeroes - %d\n", zeroes_count);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the number
0
No of leading zeroes - 32
[root@localhost coding_practice]# ./a.out
Enter the number
1
No of leading zeroes - 31
[root@localhost coding_practice]# ./a.out
Enter the number
2
No of leading zeroes - 30
[root@localhost coding_practice]# ./a.out
Enter the number
6
No of leading zeroes - 29
[root@localhost coding_practice]# ./a.out
Enter the number
7
No of leading zeroes - 29
[root@localhost coding_practice]# ./a.out
Enter the number
8
No of leading zeroes - 28
[root@localhost coding_practice]# ./a.out
Enter the number
15
No of leading zeroes - 28
[root@localhost coding_practice]# ./a.out
Enter the number
16
No of leading zeroes - 27
[root@localhost coding_practice]# ./a.out
Enter the number
256
No of leading zeroes - 23
[root@localhost coding_practice]# ./a.out
Enter the number
254
No of leading zeroes - 24
[root@localhost coding_practice]# ./a.out
Enter the number
8
No of leading zeroes - 28
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the number
16
No of leading zeroes - 27
[root@localhost coding_practice]# ./a.out
Enter the number
32
No of leading zeroes - 26
[root@localhost coding_practice]# ./a.out
Enter the number
31
No of leading zeroes - 27
[root@localhost coding_practice]# ./a.out
Enter the number
33
No of leading zeroes - 26
*/
