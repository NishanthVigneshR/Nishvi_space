#include <stdio.h>

int main() {
	int var = 0;
	int mask = 0xffff;

	printf("Enter the number\n");
	scanf("%d", &var);

	var = var ^ mask;
	//var = ~(var);		// in site, they mentioned this and 2's complement will be performed.

	printf("Variable after fliping all the bits - %d\n", var);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the number
1
Variable after fliping all the bits - 65534
[root@localhost coding_practice]#
[root@localhost coding_practice]# ./a.out
Enter the number
0
Variable after fliping all the bits - 65535
[root@localhost coding_practice]# ./a.out
Enter the number
65535
Variable after fliping all the bits - 0
[root@localhost coding_practice]# ./a.out
Enter the number
65534
Variable after fliping all the bits - 1
[root@localhost coding_practice]# ./a.out
Enter the number
7
Variable after fliping all the bits - 65528
[root@localhost coding_practice]# ./a.out
Enter the number
65528
Variable after fliping all the bits - 7
*/
