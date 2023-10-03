#include <stdio.h>

int main() {
	char string[20] = {0};
	int index = 0;

	printf("Enter the string\n");
	scanf("%s", string);

	for (index = 0;string[index] != '\0';index++);

	printf("The length of the given string is %d\n", index);
}

/* Output:
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * AllTheBest!!
 * The length of the given string is 12
 */
