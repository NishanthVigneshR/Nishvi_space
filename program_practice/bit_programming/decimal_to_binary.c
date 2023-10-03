#include <stdio.h>
#include <math.h>

void convert_decimaltobinary (int * dec) {
	long long ret = 0;
	long long prev_ret = 0;
	int tmp_dec = *dec;
	int remainder = 0;
	int i = 0;

	while (tmp_dec != 0) {
		remainder = tmp_dec % 2;
		prev_ret = ret;
		ret = (remainder * pow(10, i)) + prev_ret;
		i++;
		tmp_dec = tmp_dec / 2;
	}
	printf("The binary equivalent for the decimal %d is %lld\n", *dec, ret);
}
		

int main() {
	int decimal = 0;

	printf("Enter the decimal to be converted to binary\n");
	scanf("%d", &decimal);

	convert_decimaltobinary(&decimal);
	return 0;
}

//Output
/*
 [root@localhost bit_programming]# ./decimal_to_binary
Enter the decimal to be converted to binary
15
The binary equivalent for the decimal 15 is 1111
[root@localhost bit_programming]# ./decimal_to_binary
Enter the decimal to be converted to binary
100
The binary equivalent for the decimal 100 is 1100100
[root@localhost bit_programming]#
[root@localhost bit_programming]# ./decimal_to_binary
Enter the decimal to be converted to binary
128
The binary equivalent for the decimal 128 is 10000000
[root@localhost bit_programming]# ./decimal_to_binary
Enter the decimal to be converted to binary
1
The binary equivalent for the decimal 1 is 1
[root@localhost bit_programming]# ./decimal_to_binary
Enter the decimal to be converted to binary
0
The binary equivalent for the decimal 0 is 0
*/
