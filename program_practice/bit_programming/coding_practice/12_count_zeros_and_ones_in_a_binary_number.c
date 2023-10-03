#include <stdio.h>
#include <stdint.h>

int main() {
	int8_t var = 0;
	int i = 0;
	int zeroes_count = 0;
	int ones_count = 0;

	printf("Enter the variable\n");
	scanf("%d", &var);

	for (i=0; i < (sizeof(int8_t) * 8); i++) {
		if (var >> i & 1)
			ones_count++;
		else
			zeroes_count++;
	}
	printf("Variable is %d and zeroes count [%d] and ones count [%d]\n", var, zeroes_count, ones_count);
}

/* Output :
 * [root@localhost coding_practice]# ./a.out
Enter the variable
4
Variable is 4 and zeroes count [7] and ones count [1]
[root@localhost coding_practice]# ./a.out
Enter the variable
1
Variable is 1 and zeroes count [7] and ones count [1]
[root@localhost coding_practice]# ./a.out
Enter the variable
0
Variable is 0 and zeroes count [8] and ones count [0]
[root@localhost coding_practice]# ./a.out
Enter the variable
15
Variable is 15 and zeroes count [4] and ones count [4]
[root@localhost coding_practice]# ./a.out
Enter the variable
7
Variable is 7 and zeroes count [5] and ones count [3]
[root@localhost coding_practice]# ./a.out
Enter the variable
64
Variable is 64 and zeroes count [7] and ones count [1]
*/
