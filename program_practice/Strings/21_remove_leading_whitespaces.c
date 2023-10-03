#include <stdio.h>
#include <string.h>

int main() {
	char str[32] = {'\0'};
	int i = 0;

	printf("Enter the string\n");
	fgets(str, 32, stdin);

	while (str[i] == ' ') {
		i++;
	}
	int index = 0;
	while (i < strlen(str)) {
		str[index] = str[i];
		index++;
		i++;
	}
	str[index] = '\0';
	printf("str is %s\n", str);
}
/* Output:
 * root@localhost Strings]# ./a.out
Enter the string
           wer
str is wer

*/
