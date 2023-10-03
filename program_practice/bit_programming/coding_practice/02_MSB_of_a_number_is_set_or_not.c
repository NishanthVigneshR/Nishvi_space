#include <stdio.h>
#include <stdlib.h>

int main() {
	int8_t var = 0;

	printf("Enter the number (Range : -128 to 127)\n");
	scanf("%d", &var);

	// Here, I'm using 8 bits. So, right shift the variable 7 times and then perform AND with 1.
	// 8 bits - 7, 16 bits -15 like it goes on. sizeof (datatype) - 1. 
	
	var = var >> 7;
	if (var &1)
		printf("MSB is set\n");
	else
		printf("MSB is not set\n");
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the number
5
MSB is not set
[root@localhost coding_practice]# ./a.out
Enter the number
120
MSB is not set
[root@localhost coding_practice]# ./a.out
Enter the number
-1
MSB is set
[root@localhost coding_practice]# ./a.out
Enter the number
-120
MSB is set
[root@localhost coding_practice]# ./a.out
Enter the number
-127
MSB is set
[root@localhost coding_practice]# ./a.out
Enter the number
128
MSB is set
[root@localhost coding_practice]# ./a.out
Enter the number
-128
MSB is set
[root@localhost coding_practice]# ./a.out
Enter the number
-129
MSB is not set
*/
