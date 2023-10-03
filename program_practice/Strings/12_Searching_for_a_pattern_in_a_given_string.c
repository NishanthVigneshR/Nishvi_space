#include <stdio.h>
#include <string.h>

int main() {
	char string[30] = {'\0'};
	char pattern[30] = {'\0'};
	int index = 0;
	int pattern_index = 0;
	int tmp_index = 0;

	printf("Enter the string\n");
	fgets(string, 30, stdin);
	printf("Enter the pattern\n");
	scanf ("%s", pattern);

	for(index = 0;string[index] != '\0';index++) {
		tmp_index = index;
		while (string[tmp_index] == pattern[pattern_index]) {
			tmp_index++;
			pattern_index++;
		}
		if (pattern[pattern_index] == '\0') {
			printf("Pattern found at index - %d\n", index);
			return 0;
		}
		pattern_index = 0;
	}
	printf("No match found\n");
}

/* Output:
 * [root@localhost Strings]# ./a.out
Enter the string
hello
Enter the pattern
hel
Pattern found at index - 0
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
hello
Enter the pattern
el
Pattern found at index - 1
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
how are you
Enter the pattern
are
Pattern found at index - 4
[root@localhost Strings]#
[root@localhost Strings]# ./a.out
Enter the string
how are you
Enter the pattern
you
Pattern found at index - 8
*/
