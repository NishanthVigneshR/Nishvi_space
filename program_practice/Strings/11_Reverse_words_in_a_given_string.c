#include <stdio.h>
#include <string.h>

int main() {
	char string[30] = {'\0'};
	int index = 0;
	int length = 0;
	int offset = 0;
	char rev_str[30] = {'\0'};

	printf("Enter the string\n");
	fgets(string, sizeof(string), stdin);

	length = strlen(string);

	length--;
	while (length >= 0) {
		offset = length;
		if (string[length] != ' ') {
			length--;
		} else {
			offset++;
			for (;string[offset] != ' ' && string[offset] != '\n' && string[offset] != '\0';offset++) {
				rev_str[index++] = string[offset];
			}
			rev_str[index++] = ' ';
			length--;
		}
	}
	length = 0;
	while ((string[length] != ' ') &&
		(string[length] != '\0')) {
		rev_str[index++] = string[length];
		length++;
	}
	rev_str[index] = '\0';
	printf("Reversed string is %s\n", rev_str);
}

/* Output:
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * How are you
 * Reversed string is you are How
 * [root@localhost Strings]#
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * Hello
 * Reversed string is Hello
 * 
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * All the best
 * Reversed string is best the All
 */
