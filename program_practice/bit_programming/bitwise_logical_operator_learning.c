#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t var1 = 0;
	uint8_t var2 = 0;
	int result = 0;
	int result2 = 0;

BitWise_OR:
	/* By using bitwise OR,
	 * Set var1 as 10 and var2 as 7.
	 */

	var1 = var1 | 10;
	var2 = var2 | 7;  //0000 0111

	printf("The value hold by var1 - %d\n", var1);     // The value hold by var1 - 10
	printf("The value hold by var2 - %d\n", var2);	   // The value hold by var2 - 7

	// Now, initialize var as 18.
	
	//var2 = var2 | 18;  // (0000 0111) | (0001 0010) --> 0001 0111 (23).
	//The value hold by var2 - 23
	
	//So, we need to reset the bits in var2 before assigning new value to entire variable.
	
	var2 = var2 & 0;
	var2 = var2 | 18;

	 printf("The value hold by var2 - %d\n", var2);  //The value hold by var2 - 18

	//Now. var1 is 10 and var2 is 18. Let's perform bitwise OR b/w them and chk output.
	
	result = var1 | var2;  // (0000 1010) | (0001 0010) --> 0001 1010 = 26.

	printf("Resultant value after peforming bitwise between var1 [%d] and var2 [%d] - %d\n", var1, var2, result);
	//Output : Resultant value after peforming bitwise between var1 [10] and var2 [18] - 26.
	
	//Now, I'm changing 6th bit of result to 1 by using bitwise OR.
	result = result | 32; //(0001 1010) | (0010 0000) --> 0011 1010 = 58

	printf("Result value after modifying 6-bit is %d\n", result); //Result value after modifying 6-bit is 58
	
	// Consider, I need check whether result is 27 or not.
	// By performing OR operation between result and 27. I can check it.
	
	result = result | 27; //(0011 1010) | (0001 1011) = 00111011 (59)

	printf("Result is %d\n", result); // Result is 59

BitWise_AND:
	//By using bitwise AND, we can set the variable value as we need.
	// Now, the result value is 59. I need to initialize it as 10.
	
	result = result & 10; //(0011 1011) & (0000 1010) --> 0000 1010 = 10.

	printf("After AND, result value is %d\n", result); //After AND, result value is 10

	//Let's perform AND operation between var1 and var2 and store it in result.
	result = 0;
	result = var1 & var2; // (0000 1010) | (0001 0010) --> 0000 0010 = 2.

	printf("Result after performing AND operation between var1 [%d] and var2 [%d] - %d\n", var1, var2, result);
	//Output : Result after performing AND operation between var1 [10] and var2 [18] - 2 
	
	// By using AND operator, we can reset the bit values.
	// Even, we can check whether the paticular bit is on (1) or off (0).
	
	// Consider, I need to check whether the 4th bit of the result is set or not.
	result2 = result & 8; 		// (0000 0010) & (0000 1000) --> 0000 0000. 4th bit is not set.

	if (result2 == 8)		// 4th bit is off (0)
		printf("4th bit is on (1)\n");
	else
		printf("4th bit is off (0)\n");

	// Above if chk will fail, since 4th bit is not set.
	// So, chking whether 2nd bit is set or not.
	
	result2 = result & 2; 		// (0000 0010) & (0000 0010) --> 0000 0010 = 2. 2nd bit is set.

	if (result2 == 2)		// 2nd bit is on (1)
                printf("2nd bit is on (1)\n");
        else
                printf("2nd bit is off (0)\n");

Bitwise_XOR:

	// XOR is the special operator. (00 - 0, 01 - 1, 10 -1, 11 - 0)
	
	// 1] We can swap two numbers without temp variable by using XOR.
	// Now, var1 = 10 and var2 = 18.
	
	printf("Before swapping, var1 - %d and var2 - %d\n", var1, var2);
	var1 = var1 ^ var2;	 //(10 ^ 18) --> ((0000 1010) ^ (0001 0010)) --> 0001 1000 (24). --> (var1 - 24, var2 - 18)
	var2 = var1 ^ var2;	 //(24 ^ 18) --> ((0001 1000) ^ (0001 0010)) --> 0000 1010 (10). --> (var1 - 24, var2 - 10).
	var1 = var1 ^ var2;	 //(24 ^ 10) --> ((0001 1000) ^ (0000 1010)) --> 0001 0010 (18). --> (var1 - 18, var2 - 10).

	printf("After swapping, var1 - %d and var2 - %d\n", var1, var2);

	/* Output:
	 * Before swapping, var1 - 10 and var2 - 18
	 * After swapping, var1 - 18 and var2 - 10
	 */

	// Now, I'm going to perform XOR between two variables and storing it in result.
	result = var1 ^ var2; 	// (18 ^ 10) --> ((0001 0010) ^ (0000 1010)) --> 0001 1000 = 24.
	printf("Result after XOR between both the variables - %d\n", result);

	// 2] We can toggle the value of the bit by using bitwise XOR operator.
	// Now, result is 0001 1000. I'm going to XOR it with 1 (0000 0001) 5 times.
	// So, in iterations 1,3 and 5, 1st bit will be 1 and in 2 and 4 iteration, 1st bit will be 0.
	// Output will be 25 and 24.
	
	int i=1;
	while (i <= 5) {
		result = result ^ 1; // (0001 1000) ^ (0000 0001) --> 0001 1001 (25).
				     // Next iteration: (0001 1001) ^ (0000 0001) --> 0001 1000 (24).
		printf("This is iteration %d and result - %d\n", i, result);
		i++;
	}
	/* Output :
	 * This is iteration 1 and result - 25
	 * This is iteration 2 and result - 24
	 * This is iteration 3 and result - 25
	 * This is iteration 4 and result - 24
	 * This is iteration 5 and result - 25
	 */

BitWise_NOT:
	// Bitwise NOT is the compliment operator. Output will vary depends upon whether the variable is signed or unsigned.
	// If the variable is unsigned, complement of the variable will be just 1's complement and it'll be converted into 
	// corresponding decimal and result will be shown.
	
	/***** Operating Unsigned variable will be easy. Let's check it first ****/

	uint8_t var3 = 5;  // 8 bit unsigned number , 0000 0101
	var3 = ~(var3);		    // ~(5) --> ~(0000 0101) --> 1111 1010 --> 250.

	printf("Var3 (8 bit) after complement is %u\n", var3);		//Var3 after complement is 250.

	//Same value but now I'm using it as 16 bit number.
	
	uint16_t var4 = 5;  	// 16 bit unsigned number, 0000 0000 0000 0101
	var4 = ~(var4);		// ~(5) --> 1111 1111 1111 1010 --> some big number

	printf("Var4 (16 bit) after complement is %u\n", var4);		// Var4 (16 bit) after complement is 65530.

	/*---------------------------------------------------------------------------------*/

	/** Now, let's see about complementing signed variable. MSB represents sign. 2's complement will come into picture **/

	int8_t var5 = 10; // 8 bit signed number, 0000 1010.

	var5 = ~(var5);
	printf("Signed variable after complement : %d\n", var5); //Signed variable after complement : -11

	/* Let us see how we got -11.
	 *
	 * variable = 10.
	 *
	 * 1] Get the binary number : 0000 1010
	 *
	 * 2] Complement the binary : 1111 0101.
	 *    MSB of the binary is 1. It means, it's the negative number.
	 *
	 *    So, now by using 2's complement we need to convert negative binary to decimal.
	 *
	 * 3] 2's complement:
	 * 	1] complement binary     : 0000 1010.
	 * 	2] convert it to decimal : 10.
	 * 	3] Add 1 to the number   : 11.
	 * 	4] add '-' symbol        : -11.
	 *
	 * Thus, ~(10) is -11.
	 */
}


/* Final Output:
 *
 * root@localhost bit_programming]# ./bitwise_logical
 * The value hold by var1 - 10
 * The value hold by var2 - 7
 * The value hold by var2 - 18
 * Resultant value after peforming bitwise between var1 [10] and var2 [18] - 26
 * Result value after modifying 6-bit is 58
 * Result is 59
 * After AND, result value is 10
 * Result after performing AND operation between var1 [10] and var2 [18] - 2
 * 4th bit is off (0)
 * 2nd bit is on (1)
 * Before swapping, var1 - 10 and var2 - 18
 * After swapping, var1 - 18 and var2 - 10
 * Result after XOR between both the variables - 24
 * This is iteration 1 and result - 25
 * This is iteration 2 and result - 24
 * This is iteration 3 and result - 25
 * This is iteration 4 and result - 24
 * This is iteration 5 and result - 25
 * Var3 (8 bit) after complement is 250
 * Var4 (16 bit) after complement is 65530
 * Signed variable after complement : -11
 */
