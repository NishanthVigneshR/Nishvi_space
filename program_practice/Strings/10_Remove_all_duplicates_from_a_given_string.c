#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char string[40] = {0};
	char output_string[40] = {0};
	int a[255] = {0};
	int index = 0;
	int new_index = 0;

	printf("Enter the string\n");
	fgets(string, sizeof(string), stdin);

	while (string[index] != '\0') {
		if ((++a[(int)(string[index])]) == 1)
			output_string[new_index++] = string[index];
		index++;
	}
	printf("The string is %s\n", output_string);
}

/* Output:
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * hello world
 * The string is helo wrd
 * 
 * [root@localhost Strings]#
 * [root@localhost Strings]#
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * silence is a source of great strength
 * The string is silenc aourfgth
 * 
 * [root@localhost Strings]#
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * aaa  bbb ee
 * The string is a be
 */


