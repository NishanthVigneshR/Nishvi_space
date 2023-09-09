/* C program to swap two numbers using pointers. */
#include <stdio.h>

int main() {
	int a = 2;
	int b = 3;
	int *ptr1 = NULL;
	int *ptr2 = NULL;

	ptr1 = &a;
	ptr2 = &b;

	*ptr2 = *ptr1 + *ptr2;
	*ptr1 = *ptr2 - *ptr1;
	*ptr2 = *ptr2 - *ptr1;
	printf("After swapping, a - %d, b - %d\n",a, b);

}
