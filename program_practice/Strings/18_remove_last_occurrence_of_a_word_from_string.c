#include <stdio.h>
#include <string.h>

int is_word_present (char * string, char * wo, int pos) {
	int i = 0;
	if (pos != 0 && string[pos-1] != ' ')
		return 0;

	while ((wo[i] != '\0') && (string[pos] != '\0') &&
		(wo[i] == string[pos])) {
		i++;
		pos++;
	}
	if (((string[pos] == ' ') || (pos+1 == strlen(string))) &&
	    (wo[i] == '\0')) {
		return pos;
	} else {
		return 0;
	}
}


int main() {
	char str[32] = {'\0'};
	char word[32] = {'\0'};
	int str_len = 0;
	int word_len = 0;
	int i = 0;
	int res = 0;
	int index = 0;

	printf("Enter the string\n");
	//scanf("%s", str);
	fgets (str, 32, stdin);
	printf("Enter the word\n");
	scanf("%s", word);

	str_len = strlen (str);
	word_len = strlen (word);
	
	for (i = 0;i < strlen(str);i++) {
		res = is_word_present(str, word, i);
		if (res != 0)
			index = res;
	}
	for (i=0; i<strlen(str);i++) {
		if ((i + strlen(word)) == index) {
			while (index <= strlen(str)) {
				str[i] = str[index];
				i++;
				index++;
			}
		}
	}

	printf("String is %s\n", str);

}

/* Output:
 * root@localhost Strings]# ./a.out
Enter the string
how are you are you are
Enter the word
are
String is how are you are you

[root@localhost Strings]# ./a.out
Enter the string
how are how
Enter the word
how
String is how are

[root@localhost Strings]# ./a.out
Enter the string
how are you
Enter the word
how
String is  are you

[root@localhost Strings]# ./a.out
Enter the string
how are are you are
Enter the word
are
String is how are are you

[root@localhost Strings]# ./a.out
Enter the string
how are you are
Enter the word
ar
String is how are you are

[root@localhost Strings]# ./a.out
Enter the string
how are you you
Enter the word
ou
String is how are you you
*/ 
