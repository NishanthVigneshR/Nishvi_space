#include <stdio.h>

void traverse_the_string(char * str, int i) {
	while (str[i] != '\0') {
		str[i] = str[i+1];
		i++;
	}
}

int main() {
	char str[32] = {'\0'};
	int i = 0;
	int is_found = 0;

	printf("Enter the string\n");
	fgets(str, 32, stdin);

	while (str[i] != '\0') {
		is_found = 0;
		if (str[i] == ' ' && str[i+1] == ' ') {  //' a'
			printf("if success\n");
			is_found = 1;
			int j = i;
			while (str[j] != '\0') {
				printf("str[%d] is %c and str[%d] is %c\n", j, str[j], j+1, str[j+1]);
				str[j] = str[j+1];
				j++;
			}
			str[j] = '\0';
		}
		if (!is_found) {
		    i++;
		}
	}
	printf("Str is %s\n", str);
}
