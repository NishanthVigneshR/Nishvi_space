#include <stdio.h>

int main() {
	int var = 0;
	int i = 0;
	int highest_set_bit = -1;

	printf("Enter the number\n");
	scanf("%d", &var);

	for (i=0; i < (sizeof(int) * 8); i++) {
		if ((var >> i) & 1)
			highest_set_bit = i;
	}
	if (highest_set_bit == -1)
		printf("All the bits are not set\n");
	else
		printf("Highest bit set - %d\n", highest_set_bit);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the number
1
Highest bit set - 0
[root@localhost coding_practice]# ./a.out
Enter the number
4
Highest bit set - 2
[root@localhost coding_practice]# ./a.out
Enter the number
8
Highest bit set - 3
[root@localhost coding_practice]# ./a.out
Enter the number
16
Highest bit set - 4
[root@localhost coding_practice]# ./a.out
Enter the number
25000
Highest bit set - 14
[root@localhost coding_practice]# ./a.out
Enter the number
65535
Highest bit set - 15
[root@localhost coding_practice]# ./a.out
Enter the number
65534
Highest bit set - 15
[root@localhost coding_practice]# ./a.out
Enter the number
65536
Highest bit set - 16
*/
