#include <stdio.h>

int main() {
	int var = 0;
	int bits[32] = {0};
	int i = 0;
	int bit = 0;

	printf("Enter the number\n");
	scanf("%d", &var);

	for (i = 31; i >= 0; i--) {
	    bit = (var >> i) & 1;
	    bits[i] = bit;
	}

	printf("\n");
	for (i = 31; i >= 0; i--) {
		printf("%d", bits[i]);
	}
	printf("\n");
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the number
2

00000000000000000000000000000010
[root@localhost coding_practice]# ./a.out
Enter the number
3

00000000000000000000000000000011
[root@localhost coding_practice]# ./a.out
Enter the number
1

00000000000000000000000000000001
[root@localhost coding_practice]# ./a.out
Enter the number
256

00000000000000000000000100000000
[root@localhost coding_practice]# ./a.out
Enter the number
255

00000000000000000000000011111111
*/
