#include <stdio.h>
#include <math.h>

double pow(double x, double y);

int convert_binarytodecimal(long long * bin) {
	long long tmp_bin = *bin;
	int ret = 0;
	int bit = 0;
	double i = 0;

	while (tmp_bin != 0) {
		bit = tmp_bin % 10;
		tmp_bin = tmp_bin/10;
		ret = ret + (bit * pow (2, i));
		i++;
	}
	return ret;
}

int main() {
	long long binary = 0;
	int result = 0;
	printf("Enter the binary which needs to be converted to decimal\n");

	scanf("%lld", &binary);

	result = convert_binarytodecimal(&binary);

	printf("The decimal equivalent for binary %lld is %d\n", binary, result);
}

/* Output:
 * gcc binary_to_decimal.c -lm -o binary_to_decimal
 * [root@localhost bit_programming]# ./binary_to_decimal
 * 
 * Enter the binary which needs to be converted to decimal
 * 10010111
 * The decimal equivalent for binary 10010111 is 151
 * [root@localhost bit_programming]#
 * [root@localhost bit_programming]# ./binary_to_decimal
 * Enter the binary which needs to be converted to decimal
 * 00110111
 * The decimal equivalent for binary 110111 is 55
 */
