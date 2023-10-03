#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char string[50] = {0};
	int arr[26] = {0};
	int index = 0;
	int val = 0;
	int max = 0;

	printf("Enter the string\n");
	fgets(string, sizeof(string), stdin);

	while (string[index] != '\0') {
		if ((tolower(string[index]) >= 'a') && (tolower(string[index]) <= 'z')) {
			val = tolower(string[index]) - 97;
			arr[val]++;
		}
		index++;
	}
	
	for (index = 0;index <26;index++) {
		if (arr[index] > arr[max]) {
			max = index;
		}
	}
	printf("%c letter repeated maximum %d times\n", (char) (97 + max), arr[max]);
}

/* Output:
 * [root@localhost Strings]# ./a.out
Enter the string
Elephant
e letter repeated maximum 2 times
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
malayalam
a letter repeated maximum 4 times
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
This is mississippi
i letter repeated maximum 6 times
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
This is mississippis
s letter repeated maximum 7 times
*/
