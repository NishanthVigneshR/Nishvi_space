#include <stdio.h>

int main() {
	int var = 0;
	int lowest_set_bit = -1;
	int i = 0;

	printf("Enter the variable\n");
	scanf("%d", &var);

	for (i = 0; i < (sizeof(int) * 8); i++) {
		if (var >> i & 1) {
			lowest_set_bit = i;
			break;
		}
	}
	if (lowest_set_bit == -1)
		printf("No bits set\n");
	else
		printf("lowest set bit is %d\n", lowest_set_bit);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the variable
1
lowest set bit is 0
[root@localhost coding_practice]# ./a.out
Enter the variable
0
No bits set
[root@localhost coding_practice]# ./a.out
Enter the variable
2
lowest set bit is 1
[root@localhost coding_practice]# ./a.out
Enter the variable
8
lowest set bit is 3
[root@localhost coding_practice]# ./a.out
Enter the variable
16
lowest set bit is 4
[root@localhost coding_practice]# ./a.out
Enter the variable
15
lowest set bit is 0
[root@localhost coding_practice]# ./a.out
Enter the variable
6
lowest set bit is 1
[root@localhost coding_practice]# ./a.out
Enter the variable
1
lowest set bit is 0
[root@localhost coding_practice]# ./a.out
Enter the variable
25251
lowest set bit is 0
[root@localhost coding_practice]# ./a.out
Enter the variable
25250
lowest set bit is 1
[root@localhost coding_practice]# ./a.out
Enter the variable
31
lowest set bit is 0
[root@localhost coding_practice]# ./a.out
Enter the variable
30
lowest set bit is 1
[root@localhost coding_practice]# ./a.out
Enter the variable
4
lowest set bit is 2
*/
