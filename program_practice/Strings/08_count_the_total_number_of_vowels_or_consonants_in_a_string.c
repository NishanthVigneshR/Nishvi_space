#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char string[30] = {0};
	int index = 0;
	int vowels_count = 0;
	int constraints_count = 0;

	printf("Enter the string\n");
	fgets(string, sizeof(string), stdin);

	while (string[index] != '\0') {
		if ((tolower(string[index]) == 'a') ||
		    (tolower(string[index]) == 'e') ||
		    (tolower(string[index]) == 'i') ||
		    (tolower(string[index]) == 'o') ||
		    (tolower(string[index]) == 'u'))
		    vowels_count += 1;
#if 0
		else if (((tolower(string[index]) > 'a') && (tolower(string[index]) < 'e')) ||
			 ((tolower(string[index]) > 'e') && (tolower(string[index]) < 'i')) ||
			 ((tolower(string[index]) > 'i') && (tolower(string[index]) < 'o')) ||
			 ((tolower(string[index]) > 'o') && (tolower(string[index]) < 'u')) ||
			 ((tolower(string[index]) > 'u') && (tolower(string[index]) <= 'z')))
#endif
		else if ((tolower(string[index]) > 'a') && ((tolower(string[index]) <= 'z')))
			constraints_count += 1;
		index++;
	}
	printf("Number of vowels count : %d\nNumber of constraints count : %d\n", vowels_count, constraints_count);
}

/* Output:
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * abcdefghijklmnopqrstuvwxyz
 * Number of vowels count : 5
 * Number of constraints count : 21
 */

