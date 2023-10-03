#include <stdio.h>
#include <string.h>

int main() {
	char string[20] = {'\0'};
	char var;
	int index = 0;
	int count = 0;

	printf("Enter the string\n");
	fgets(string, 20, stdin);

	printf("Enter the character whose frequency need to be found\n");
	scanf("%c", &var);

	for (index = 0;string[index] != '\0'; index++) {
		if (string[index] == var)
			count++;
	}
	printf("%c character found %d times in the buffer %s", var, count, string);
}
/* Output:
 * [root@localhost Strings]# ./a.out
Enter the string
mississippi
Enter the character whose frequency need to be found
s
s character found 4 times in the buffer mississippi
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
ammappaaa
Enter the character whose frequency need to be found
a
a character found 5 times in the buffer ammappaaa
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
amma appa
Enter the character whose frequency need to be found
a
a character found 4 times in the buffer amma appa
*/
