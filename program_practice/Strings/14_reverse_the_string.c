#include <stdio.h>
#include <string.h>

int main() {
	char string[20] = {0};
	int index = 0;
	char tmp;
	int length = 0;

	printf("Enter the string\n");
	scanf("%s", string);

	length = strlen(string);
	while (index < (length/2)) {
		tmp = string[index];
		string[index] = string[(length - 1) - index];
		string[(length - 1) - index] = tmp;
		index++;
	}
	printf("\nReversed string : %s\n", string);
}

/* Output:
 * [root@localhost Strings]# ./a.out
Enter the string
Tamil

Reversed string : limaT
[root@localhost Strings]# ./a.out
Enter the string
English

Reversed string : hsilgnE
*/
