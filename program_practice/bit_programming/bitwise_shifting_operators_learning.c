#include <stdio.h>
#include <stdint.h>

int main() {

left_shift:
unsigned_variable:
	uint8_t var1 = 15;  //0000 1111

	// By using, left shift operator we can move the bits.
	// Shifting more than allocated bit number, will throw unexpected behaviour.
	// Trailing bits will be filled with 0.
	// variable * (2^n)
	
	var1 = var1 << 1; // 0000 1111 --> 0001 1110 = 30
	printf("variable after left shift with 1 : %d\n", var1);

	var1 = var1 << 3; // 0001 1110 --> 1111 0000 = 240 
	printf("Variable after 3 left shift  - %d\n", var1);

	var1 = var1 << 4; // 1111 0000 --> 0000 0000 = 0
	printf("Variable after 4 more left shift - %d\n", var1);

	/* Output:
	 * [root@localhost bit_programming]# ./bitwise_shift
	 * variable after left shift with 1 : 24
	 * Variable after 3 left shift  - 240
	 * Variable after 4 more left shift - 0
	 */

Signed_variable:
	//Using the same number and shifting which I used already for unsigned left shift.//
	
	 int8_t var2 = 15;  //0000 1111 , signed number

        // By using, left shift operator we can move the bits.
        // Shifting more than allocated bit number, will throw unexpected behaviour.
        // Trailing bits will be filled with 0.
        // variable * (2^n)

        var2 = var2 << 1; // 0000 1111 --> 0001 1110 = 30
        printf("variable after left shift with 1 : %d\n", var2);

        var2 = var2 << 3; // 0001 1110 --> 1111 0000.
	/* Here, MSB is 1. It means it's negative binary. So, 2's complement will come into picture.
	 * complement = 0000 1111. Equivalent decimal = 15. Add 1 to it --> 16. Then, add '-'. ---> -16.
	 */
        printf("Variable after 3 left shift  - %d\n", var2);

        var2 = var2 << 4; // 1111 0000 --> 0000 0000 = 0
        printf("Variable after 4 more left shift - %d\n", var2);

	/* Output :
	 * variable after left shift with 1 : 30
	 * Variable after 3 left shift  - -16
	 * Variable after 4 more left shift - 0
	 */


Right_shift:
	/* Right shift bitwise operator is used to shift the bits to the right.
	 * In case of unsigned variable, trailing bits will be filled with 0.
	 * In case of Signed variable, trailing bits will be filled with the value present in sign bit.
	 * variable / (2 ^n).
	 */
Unsigned_variable_RS:
	uint8_t var3 = 15;  // 0000 1111
	
	var3 = var3 >> 1;   // 0000 0111 --> 7
	printf("Variable after 1 right shift - %d\n", var3);

	var3 = var3 >> 2;   // 0000 0001 --> 1
	printf("Variable after next 2 more right shift - %d\n", var3);

	var3 = var3 >> 2;  // 0000 0000 --> 0
	printf("Variable after another 2 more right shift - %d\n", var3);

	/* Output:
	 * Variable after 1 right shift - 7
	 * Variable after next 2 more right shift - 1
	 * Variable after another 2 more right shift - 0
	 */

Signed_variable_RS:
	int8_t var4 = 15;  // 0000 1111

	var4 = var4 >> 2;  // 0000 0011 --> 3
	printf("signed Variable after 2 right shift - %d\n", var4);

	var4 = ~(var4);   // ~(0000 0011) --> 1111 1100 --> 0000 0011 -->(+1) --> 0000 0100 --> -4 (0000 0100).
	printf("var4 after complement is %d\n", var4);

	var4 = var4 >> 2;  // ((1000 0100) >> 2) --> 0000 0001 --> -1

	printf("Var4 after 2 right shift - %d\n", var4);
}
