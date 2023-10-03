#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char string1[20] = {'\0'};
	char string2[20] = {0};
	int index = 0;

	printf("Enter the first string\n");
	scanf("%s", string1);

	printf("\nEnter the second string\n");
	scanf("%s", string2);

	if (strlen(string1) != strlen(string2)) {
		printf("\nThe provided strings are different, str1 - %s, str2 - %s\n", string1, string2);
		return 0;
	}

	index = 0;
	while (string1[index] != '\0') {
		if (tolower(string1[index]) != tolower(string2[index])) {  //Used tolower to avoid case sensitive
			printf("\nThe provided strings are different, str1 - %s, str2 - %s\n", string1, string2);
			return 0;
		}
		index++;
	}
	printf("\nThe provided strings are same, str1 - %s, str2 - %s\n", string1, string2);
	return 0;
}

/* Output:
 * [root@localhost Strings]# ./a.out
Enter the first string
Hello

Enter the second string
Hello

The provided strings are same, str1 - Hello, str2 - Hello
[root@localhost Strings]#
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the first string
Hello

Enter the second string
Helloo

The provided strings are different, str1 - Hello, str2 - Helloo
[root@localhost Strings]#
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the first string
Hello

Enter the second string
Hell

The provided strings are different, str1 - Hello, str2 - Hell
[root@localhost Strings]#
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the first string
String

Enter the second string
Array

The provided strings are different, str1 - String, str2 - Array

[root@localhost Strings]# ./a.out
Enter the first string
String

Enter the second string
string

The provided strings are same, str1 - String, str2 - string
*/
