#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char string[40] = {0};
	int index = 0;
	int ascii_value = 0;
	int symbol_count = 0;
	int number_count = 0;
	int alphabets_count = 0;

	printf("Enter the string\n");
	fgets(string, sizeof(string), stdin);

	while (string[index] != '\0') {
		ascii_value = 0;
		ascii_value = (int )string[index];
		if (((ascii_value >= 33) && (ascii_value < 48))   ||
		    ((ascii_value > 122) && (ascii_value <= 126)) ||
		    ((ascii_value >= 91) && (ascii_value <= 96))  ||
		    ((ascii_value >= 58) && (ascii_value <= 64))  ||
		    (string[index] == ' '))
			symbol_count += 1;
		else if ((ascii_value >= 48) && (ascii_value <= 57))      //0 to 9
			number_count += 1;
		else if (((ascii_value >= 65) && (ascii_value <= 90)) ||  //A to Z
			 ((ascii_value >= 97) && (ascii_value <= 122)))   //a to z
			alphabets_count += 1;
		index++;
	}
	printf("Number of symbols : %d\nNumber of alphabets : %d\nNumber of numerics : %d\n",
		symbol_count, number_count, alphabets_count);
}

/* Output:
 * [root@localhost Strings]# ./a.out
 * Enter the string
 * "Roll Number" : 1234..!!
 * Number of symbols : 10
 * Number of alphabets : 4
 * Number of numerics : 10
 */

