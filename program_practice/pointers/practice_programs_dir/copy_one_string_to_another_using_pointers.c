/* C program to copy one string to another using pointers. */

#include <stdio.h>

int main() {
	char str1[] = "hellodude";
	char str2[10] = {'\0'};
	char * ptr1 = NULL;
	char * ptr2 = NULL;
	ptr1 = str1;
	ptr2 = str2;

	while (*ptr1 != '\0') {
		*ptr2 = *ptr1;
		ptr2++;
		ptr1++;
	}
	printf("After copying, str2 is %s", str2);
}
