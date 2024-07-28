#include <stdio.h>
#include <string.h>

int main() {
	char var[10] = {'\0'};
	int result = 0;
	int index = 0;

	printf("Enter the number :\n");
	scanf("%s", var);

	while (var[index] != '\0') {
		result = (result *10) + ((int)var[index] - 48);
		index++;
	}
	printf("The provided number is %d\n", result);
}

/* Output:
 * [root@localhost Strings]# ./a.out
Enter the number :
1
The provided number is 1
[root@localhost Strings]# ./a.out
Enter the number :
3
The provided number is 3
[root@localhost Strings]# ./a.out
Enter the number :
11
The provided number is 11
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the number :
145
The provided number is 145
*/
