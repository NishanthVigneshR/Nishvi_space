#include <stdio.h>
#include <string.h>

int main() {
	char string[30] = {'\0'};
	int length = 0;
	int words_count = 1;

	printf("Enter the string\n");
	//scanf("%[^\n]", string);
	fgets(string, sizeof(string), stdin);

	length = strlen(string);

	length--;
	while (length >= 0) {
		if((string[length] == ' ') &&
		   (string[length-1] != ' ')) {
		    words_count += 1;
		}
		length--;
	}
	printf("The number of words is %d\n", words_count);
}

/* Output:
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * Hello welcome This is string program
 * The number of words is 6
 * [root@localhost Strings]#
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * Hello    This   is string
 * The number of words is 4
 */

