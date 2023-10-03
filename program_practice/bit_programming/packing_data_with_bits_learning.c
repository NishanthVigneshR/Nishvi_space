//Pack the data in bits.
// 3 flags
// 1 8 bit number
// 1 16 bit number


#include <stdio.h>

int main() {
	int integer = 0;
	int result = 0;
	// Assume bit 0-15 as 16 bit number.
	// 16-23 as 8-bit number
	// 24,25 and 26 as f1, f2, and f3.
	
	//Set f1 as on.
	result = 1 << 24; // So, now result is 0000 0001 0000 0000 0000 0000 0000 0000
	integer = integer | result;  // 0000 0001 0000 0000 0000 0000 0000 0000

	// Now, set f3 flag on on.
	result = 1 << 26;   // 0000 0100 0000 0000 0000 0000 0000 0000
	integer = integer | result; // 0000 0101 0000 0000 0000 0000 0000 0000
	
	//Set the 8-bit number 129.
	result = 129 << 16; // 0000 0000 1000 0001 0000 0000 0000 0000
	integer = integer | result; // 0000 0101 100 0001 0000 0000 0000 0000
	printf("f1 set and now the integer is %d\n", integer);

	// set the 16-bit number 192.
	//16 bit number starts with 0-bit. So. no need to shift it.
	integer = integer | 192; // 0000 0101 1000 0001 0000 0000 1100 0000

get:
	//chking whether the f3 is set or not. f3 is 26th bit.
	result = integer >> 26;  //0000 0101 1000 0001 0000 0000 1100 0000 --> 0000 0000 0000 0000 0000 0000 0000 0001
	result = result & 1;
	printf("f3 is %d\n", result);

	//get f2 an f1.
	result = integer >> 25; //0000 0000 0000 0000 0000 0000 0000 0010
        result = result & 1;
        printf("f2 is %d\n", result);

	result = integer >> 24; //0000 0000 0000 0000 0000 0000 0000 0101
        result = result & 1;
        printf("f1 is %d\n", result);

	//get the 8-bit number (16-23)
	result = integer >> 16; // 0000 0000 0000 0000 0000 0101 1000 0001
	result = result & 0xff;
	printf("8-bit number is %d\n", result);

	//get 16-bit number
	result = integer & 0xffff;
	printf("16-bit number is %d\n", result);
}

/* Output:
 * [root@localhost bit_programming]# ./a.out
f1 set and now the integer is 92340224
f3 is 1
f2 is 0
f1 is 1
8-bit number is 129
16-bit number is 192
*/
