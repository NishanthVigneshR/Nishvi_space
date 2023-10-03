#include <stdio.h>

typedef struct bitfield {
	unsigned int : 5;
	unsigned int f1:1;
	unsigned int f2:1;
	unsigned int f3:1;
	unsigned int _8bitnum:8;
	unsigned int word:16;
}bit_field_t;

int main() {
	bit_field_t integer;
	int result = 0;

	//set f1 and f2.
	integer.f1 = 1;
	integer.f2 = 1;
	integer.f3 = 0;

	//set 8-bit number
	integer._8bitnum = 127;

	//set 16-bit word
	integer.word = 512;

get:
	printf("Structure values are:\nf1:%u\nf2:%u\nf3:%u\n8bit number : %u\n16-bit num : %u\n", integer.f1, integer.f2, integer.f3, integer._8bitnum, integer.word);
}

/* Output:
 * [root@localhost bit_programming]# ./a.out
Structure values are:
f1:1
f2:1
f3:0
8bit number : 127
16-bit num : 512
*/
