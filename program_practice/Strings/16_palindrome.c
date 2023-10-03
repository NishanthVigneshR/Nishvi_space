#include <stdio.h>
#include <string.h>

int main() {
	char string[20] = {'\0'};
	int length = 0;
	int index = 0;
	
	printf("Enter the string\n");
	scanf("%s", string);

	length = strlen(string);

	while (index < (length/2)) {
		if (string[index] != string[(length - 1) - index]) {
			printf("\nGiven string %s is not palindrome\n", string);
			return 0;
		}
		index++;
	}
	printf("\nGiven string %s is palindrome\n", string);
        return 0;
}

/* Output:
 * [root@localhost Strings]# ./a.out
Enter the string
malayalam

Given string malayalam is palindrome
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
tamil

Given string tamil is not palindrome
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
amma

Given string amma is palindrome
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
appa

Given string appa is palindrome
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
uncle

Given string uncle is not palindrome
*/
