#include <stdio.h>

int main() {
	int var1 = 0;
	int var2 = 0;

	printf("Enter the variables\n");
	scanf("%d %d", &var1, &var2);

	printf("Variables before swapping : %d %d\n", var1, var2);

	var1 = var1 ^ var2;
	var2 = var1 ^ var2;
	var1 = var1 ^ var2;

	printf("Variables after swapping : %d %d\n", var1, var2);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the variables
10
15
Variables before swapping : 10 15
Variables after swapping : 15 10
[root@localhost coding_practice]# ./a.out
Enter the variables
300
10003
Variables before swapping : 300 10003
Variables after swapping : 10003 300
*/
