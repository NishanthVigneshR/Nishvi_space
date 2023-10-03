#include <stdio.h>

int main() {
	int num = 0;

	printf("Enter the number\n");
	scanf("%d", &num);

	if (num & 1)
		printf("Provided number %d is odd\n", num);
	else
		printf("Provided number %d is even\n", num);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the number
120
Provided number 120 is even
[root@localhost coding_practice]# ./a.out
Enter the number
251
Provided number 251 is odd
*/
