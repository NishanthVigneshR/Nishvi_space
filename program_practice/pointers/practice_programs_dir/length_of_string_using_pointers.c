/* C program to find length of string using pointers. */

#include <stdio.h>

int main() {
	char str[] = "mobaxterm";
	char *ptr = NULL;
	int count = 0;
	ptr = str;

	while (*ptr != '\0') {
		count++;
		ptr++;
	}
	printf("Length of string - %d\n", count);
}
