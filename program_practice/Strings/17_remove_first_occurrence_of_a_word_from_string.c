#include <stdio.h>
#include <string.h>

void remove_word_from_str(char * string, int rem_index, int mod_index) {
	int len = strlen(string);
	while (mod_index != len) {
	    string[rem_index] = string[mod_index];
	    rem_index++;
	    mod_index++;
	}
	string[rem_index] = '\0';
}

int is_word_present(char * s, char * wo, int str_pos) {
	int i = 0;
	if ((str_pos != 0) && (s[str_pos-1] != ' '))    // checks whether th previous byte is ' '.
	       return 0;	
	while ((s[str_pos] != '\0') && (s[str_pos] == wo[i])) {
		i++;
		str_pos++;
	}
	if ((wo[i] == '\0') && ((s[str_pos] == ' ') || str_pos+1 == strlen(s)))  // '\n' also will come last before for fgets.
										 // chking whether next bit of str is ' ' | EOS.
		return str_pos;
	else
		return 0;
}

int main() {
	char str[32] = {'\0'};
	char word[32] ={0};
	int i = 0;
	int j = 0;
	int k = 0;
	int res = 0;

	printf("Enter the string\n");
	fgets(str, 32, stdin);
	printf("Enter the word which need to be removed\n");
	scanf("%s", word);

#if 1
	while (str[i] != '\0') {
		res = is_word_present (str, word, i);
		if (res != 0) {
		    remove_word_from_str(str, i, res);
		    break;
		} 
		i++;
	}
#endif
	printf("String is %s\n", str);
}

/* Output:
[root@localhost Strings]# ./a.out
Enter the string
how are you
Enter the word which need to be removed
how
String is  are you

[root@localhost Strings]# ./a.out
Enter the string
how are you are
Enter the word which need to be removed
are
String is how  you are

[root@localhost Strings]# ./a.out
Enter the string
how are you
Enter the word which need to be removed
you
String is how are

[root@localhost Strings]# ./a.out
Enter the string
how are you
Enter the word which need to be removed
ho
String is how are you

[root@localhost Strings]# ./a.out
Enter the string
how are you
Enter the word which need to be removed
ow
String is how are you

[root@localhost Strings]# ./a.out
Enter the string
how are how are you
Enter the word which need to be removed
how
String is  are how are you
*/
