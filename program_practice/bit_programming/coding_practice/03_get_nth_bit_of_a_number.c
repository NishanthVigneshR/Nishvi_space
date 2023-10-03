#include <stdio.h>

int main() {
	int var = 0;
	int nthbit = 0;

	printf("Enter the number\n");
	scanf("%d", &var);
	printf("Enter the nth bit which needs to be fetched\n");
	scanf("%d", &nthbit);

	if ((var >> nthbit) & 1)
		printf("nth bit [%d] of the variable [%d] is 1\n", nthbit, var);
	else
		printf("nth bit [%d] of the variable [%d] is 0\n", nthbit, var);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the number
10
Enter the nth bit which needs to be fetched
1
nth bit [1] of the variable [10] is 1
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the number
10
Enter the nth bit which needs to be fetched
0
nth bit [0] of the variable [10] is 0
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the number
10
Enter the nth bit which needs to be fetched
4
nth bit [4] of the variable [10] is 0
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the number
10
Enter the nth bit which needs to be fetched
3
nth bit [3] of the variable [10] is 1
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the number
15
Enter the nth bit which needs to be fetched
0
nth bit [0] of the variable [15] is 1
[root@localhost coding_practice]# ./a.out
Enter the number
15
Enter the nth bit which needs to be fetched
1
nth bit [1] of the variable [15] is 1
[root@localhost coding_practice]# ./a.out
Enter the number
15
Enter the nth bit which needs to be fetched
2
nth bit [2] of the variable [15] is 1
[root@localhost coding_practice]# ./a.out
Enter the number
15
Enter the nth bit which needs to be fetched
3
nth bit [3] of the variable [15] is 1
[root@localhost coding_practice]# ./a.out
Enter the number
15
Enter the nth bit which needs to be fetched
4
nth bit [4] of the variable [15] is 0
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the number
15
Enter the nth bit which needs to be fetched
30
nth bit [30] of the variable [15] is 0
*/
