#include <stdio.h>

int main() {
	int var = 0;
	int result = 0;

	printf("Enter the number\n");
	scanf("%d", &var);

	result = var & 1;

	if (result == 1)
		printf("LSB is set in var [%d]\n", var);
	else
		printf("LSB is not set in var [%d]\n", var);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the number
10
LSB is not set in var [10]
[root@localhost coding_practice]# ./a.out
Enter the number
5
LSB is set in var [5]
[root@localhost coding_practice]# ./a.out
Enter the number
240
LSB is not set in var [240]
[root@localhost coding_practice]# ./a.out
Enter the number
231
LSB is set in var [231]
*/
