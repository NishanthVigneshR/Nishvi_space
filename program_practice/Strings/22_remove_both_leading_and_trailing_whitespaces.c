#include <stdio.h>
#include <string.h>

int main() {
	char str[32] = {'\0'};
	int i=0;
	int j = 0;
	int trail_index = -1;
	int leading_index = -1;

	printf("Enter the string\n");
	fgets(str, 32, stdin);

	while (str[i] == ' ') {
		i++;
	}
	leading_index = i;

	while (str[i] != '\0') {
		if (str[i+1] == '\n' || str[i+1] == '\0')
			break;

		if (str[i] != ' ' && str[i+1] == ' ') {
		    trail_index = i;
		} else if (str[i] == ' ' && str[i+1] != ' ') {
			trail_index = -1;
		}
		i++;
	}
	if (trail_index != -1) {
	    while (leading_index <= trail_index) {
		str[j++] = str[leading_index++];
	    }
	    str[j] = '\0';
	} else {
		while (str[leading_index] != '\0') {
			str[j++] = str[leading_index++];
		}
		str[j] = '\0';
	}
	printf("str is %s\n",str);
}

/* Output:
 * [root@localhost Strings]# ./a.out
Enter the string
     aew
str is aew

[root@localhost Strings]# ./a.out
Enter the string
   asd
str is asd
[root@localhost Strings]# ./a.out
Enter the string
asd
str is asd
[root@localhost Strings]# ./a.out
Enter the string
asd   q
str is asd   q

[root@localhost Strings]# ./a.out
Enter the string
a  se
str is a  se

[root@localhost Strings]# ./a.out
Enter the string
aa   wer   we
str is aa   wer   we
*/
