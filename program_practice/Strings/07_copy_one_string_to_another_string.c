#include <stdio.h>
#include <string.h>

int main() {
	char string1[50] = {0};
	char string2[50] = {0};
	int index = 0;

	printf("Enter the string\n");
	fgets(string1, sizeof(string1), stdin);
	for (; string1[index] != '\0'; index++)
		string2[index] = string1[index];

	//strcpy(string2, string1);
	printf("The copied string is %s\n", string2);
}

/* Output:
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * Hello This is string program based on copy
 * The copied string is Hello This is string program based on copy
 */

