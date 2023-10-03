#include <stdio.h>
#include <stdlib.h>

int main() {
	char string[20] = {0};

	printf("Enter the string to be printed\n");
	scanf("%s", string);

	printf("The provided string is %s\n", string);
}

/* Output:
 * [root@localhost Strings]# ./a.out
 * Enter the string to be printed
 * Hello
 * The provided string is Hello
 */

