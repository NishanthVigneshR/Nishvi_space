/* C program to find the sum of two numbers using pointers.c */

#include <stdio.h>

int main() {
	int a =10;
        int b = 20;
	int *ptr1 = NULL;
	int *ptr2 = NULL;

	ptr1 = &a;
	ptr2 = &b;

	printf("The result is %d\n", *ptr1 + *ptr2);
}
