#include <stdio.h>

int main() {
	int var = 0;
	int zeros_count = 0;
	int i = 0;

	printf("Enter the variable\n");
	scanf("%d", &var);

	for (i = 0;i < (sizeof(int) * 8); i++) {
		if (!(var >> i & 1)) 
			zeros_count++;
		else
			break;
	}
	printf("No of trailing zeros : %d\n", zeros_count);
}

/* Output:
 * [root@localhost coding_practice]# ./a.out
Enter the variable
4
No of trailing zeros : 2
[root@localhost coding_practice]# ./a.out
Enter the variable
1
No of trailing zeros : 0
[root@localhost coding_practice]# ./a.out
Enter the variable
0
No of trailing zeros : 32
[root@localhost coding_practice]# ./a.out
Enter the variable
2
No of trailing zeros : 1
[root@localhost coding_practice]# ./a.out
Enter the variable
5
No of trailing zeros : 0
[root@localhost coding_practice]# ./a.out
Enter the variable
6
No of trailing zeros : 1
[root@localhost coding_practice]# ./a.out
Enter the variable
8
No of trailing zeros : 3
[root@localhost coding_practice]# ./a.out
Enter the variable
16
No of trailing zeros : 4
[root@localhost coding_practice]# ./a.out
Enter the variable
15
No of trailing zeros : 0
*/
