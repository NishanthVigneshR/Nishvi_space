#include <stdio.h>
#include <string.h>

int main() {
	char string[20] = {0};
	int index = 0;

	printf("Enter the string\n");
	scanf("%s", string);

	for (;string[index] != '\0'; index++);
	//index = strlen(string);
	
	index--;
	while (index >= 0) {
	    printf("%c ", string[index]);
	    index--;
	}
	printf("\n");
}

/* [root@localhost Strings]# ./a.out
 * Enter the string
 * cricketandfootball
 * l l a b t o o f d n a t e k c i r c
 */
