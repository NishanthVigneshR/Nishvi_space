#include <stdio.h>

int main() {
	int var = 0;
	int nbit = 0;
	int result = 0;
	int i = 1;

	printf("Enter the variable\n");
	scanf("%d", &var);
	printf("Enter the bit which needs to be toggled\n");
	scanf("%d", &nbit);

	result = 1 << nbit;
	while (i <= 4) {
		var = var ^ result;
		printf("Variable after %d toggle is %d\n", i, var);
		i++;
	}
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the variable
1
Enter the bit which needs to be toggled
0
Variable after 1 toggle is 0
Variable after 2 toggle is 1
Variable after 3 toggle is 0
Variable after 4 toggle is 1
[root@localhost coding_practice]# ./a.out
Enter the variable
15
Enter the bit which needs to be toggled
2
Variable after 1 toggle is 11
Variable after 2 toggle is 15
Variable after 3 toggle is 11
Variable after 4 toggle is 15
[root@localhost coding_practice]# ./a.out
Enter the variable
1000
Enter the bit which needs to be toggled
20
Variable after 1 toggle is 1049576
Variable after 2 toggle is 1000
Variable after 3 toggle is 1049576
Variable after 4 toggle is 1000
*/
