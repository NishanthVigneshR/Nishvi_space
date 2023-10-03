#include <stdio.h>

int main() {
	int var = 0;
	int nbit = 0;
	int res = 0;

	printf("Enter the variable\n");
	scanf("%d", &var);

	printf("Enter the nth bit which need to be set\n");
	scanf("%d", &nbit);

	printf("Received variable is %d and need to set %d bit\n", var, nbit);

	res = 1 << nbit | 1;

	var = var | res;

	printf("Variable after setting %d bit is %d\n", nbit, var);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the variable
10
Enter the nth bit which need to be set
2
Received variable is 10 and need to set 2 bit
Variable after setting 2 bit is 15
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the variable
1
Enter the nth bit which need to be set
7
Received variable is 1 and need to set 7 bit
Variable after setting 7 bit is 129
[root@localhost coding_practice]# ./a.out
Enter the variable
30
Enter the nth bit which need to be set
1
Received variable is 30 and need to set 1 bit
Variable after setting 1 bit is 31
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the variable
10
Enter the nth bit which need to be set
30
Received variable is 10 and need to set 30 bit
Variable after setting 30 bit is 1073741835
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the variable
10
Enter the nth bit which need to be set
31
Received variable is 10 and need to set 31 bit
Variable after setting 31 bit is -2147483637
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the variable
0
Enter the nth bit which need to be set
31
Received variable is 0 and need to set 31 bit
Variable after setting 31 bit is -2147483647
*/
