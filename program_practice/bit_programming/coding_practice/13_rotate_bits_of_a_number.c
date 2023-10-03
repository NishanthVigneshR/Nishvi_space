#include <stdio.h>
#include <stdint.h>

uint8_t left_to_right_rotation (uint8_t num, int rotation) {
	/* Left to right rotation logic.
	 * 0000 0111 --> 1000 0011 --> 1000 0000
         * 1 - Take LSB and store it one variable. Do AND operation with 1.
         * 2 - Right shift the variable 1 time.
         * 3 - left shift the result value to sizeof(datatype) times.
         * 4 - Perform OR operation b/w variable and result.
         * 5 - Do it in loop.
         */

	uint8_t lsb = 0;
	int i = 0;
	while (i < rotation) {
		lsb = num & 1;
		num = num >> 1;
		lsb = lsb << ((sizeof(uint8_t) * 8) -1);
		num = num | lsb;
		i++;
	}
	return num;
}

uint8_t right_to_left_rotation (uint8_t num, int rotation) {
	/* Right-Left rotation Logic.
	 * 0000 0111 --> 0000 1110 --> 0001 1100
	 * 1 - Take MSB and store it in temp variable. Left shift 1 sizeof(datatype) - 1 times and do AND operation.
	 * 2 - Left shift the number once.
	 * 3 - do OR operation between previous MSB and number.
	 * 4 - Loop it.
	 */

	uint8_t msb = 0;
	int i = 0;
	while (i < rotation) {
		msb = 1 << ((sizeof(uint8_t) * 8) -1);
		if (num & msb) 
			msb = 1;
		else
			msb = 0;
		num = num << 1;
		num = num | msb;
		i++;
	}
	return num;
}

int main() {
	uint8_t var = 0;
	int n = 0;
	uint8_t result = 0;

	printf ("Enter the number\n");
	scanf ("%u", &var);

	printf ("Enter the rotation\n");
	scanf("%d", &n);

	printf ("Provided number is %u and need to rotate %d times\n", var, n);

	result = left_to_right_rotation (var, n);
	printf("Variable %u after %d times L-R rotation is %u\n", var, n, result);

	result = right_to_left_rotation (var, n);
	printf("Variable %u after %d times R-L rotation is %u\n", var, n, result);
}

/* Output :
 * [root@localhost coding_practice]# ./a.out
Enter the number
2
Enter the rotation
1
Provided number is 2 and need to rotate 1 times
Variable 2 after 1 times L-R rotation is 1
Variable 2 after 1 times R-L rotation is 4
[root@localhost coding_practice]# ./a.out
Enter the number
2
Enter the rotation
2
Provided number is 2 and need to rotate 2 times
Variable 2 after 2 times L-R rotation is 128
Variable 2 after 2 times R-L rotation is 8
[root@localhost coding_practice]# ./a.out
Enter the number
3
Enter the rotation
4
Provided number is 3 and need to rotate 4 times
Variable 3 after 4 times L-R rotation is 48
Variable 3 after 4 times R-L rotation is 48

*/
