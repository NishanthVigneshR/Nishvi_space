/* C program to concatenate two strings using pointers. */

#include <stdio.h>

int main() {
	char str1[10] = "hey!";
	char str2[] = "buddy";
	char * ptr1 = NULL;
	char * ptr2 = NULL;

	ptr1 = str1;
	ptr2 = str2;

	while (*ptr1 != '\0') {
		ptr1++;
	}
	while (*ptr2 != '\0') {
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	printf("%s\n", str1);
}
