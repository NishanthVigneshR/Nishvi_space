#include <stdio.h>
#include <string.h>

int main() {
	char str[32] = {'\0'};
	int i =0;
	int index = -1;

	printf("Enter the string\n");
	fgets(str, 32, stdin);

	while (str[i] != '\0') {
		if (str[i] == '\n' || str[i] == '\0')
			break;

		if ((str[i+1] == ' ') && (str[i] != ' ')) {
			index = i;
		} else if ((str[i] != ' ') && (str[i-1] == ' ')) {
		       index = -1;
		}
		i++;
	}
	if (index != -1)
		str[index+1] = '\0';

	printf("Str is %s\n", str);
}
