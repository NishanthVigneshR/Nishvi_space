#include <stdio.h>

int main() {
	int var = 0;
	int nbit = 0;
	int result = 0;

	printf("Enter the variable\n");
	scanf("%d", &var);
	printf("Enter the bit to be cleared\n");
	scanf("%d", &nbit);

	printf("Received variable is %d and %d bit need to be cleared\n", var, nbit);
	result = ~(1 << nbit);
	var = var & result;

	printf("Variable after clearing %d bit is %d\n", nbit, var);
}

/* Output:
 * root@localhost coding_practice]# ./a.out
Enter the variable
10
Enter the bit to be cleared
1
Received variable is 10 and 1 bit need to be cleared
Variable after clearing 1 bit is 8
[root@localhost coding_practice]# ./a.out
Enter the variable
15
Enter the bit to be cleared
0
Received variable is 15 and 0 bit need to be cleared
Variable after clearing 0 bit is 14
*/
