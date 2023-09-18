#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int gval = 10; //Just for chking, whether entire text segment will be replaced or just main() fn part.
	       // It's getting printed even in exec call.

int main(int argc, char * argv[]) {
        printf("This is program-2\n");
	int count = 0;
	printf("Program-2 :  argc is %d\n", argc);
	printf("Global value is %d\n", gval);
	for (count = 0; count < argc; count++) {
		printf("arg %d is %s\n", count+1, argv[count]);
	}
}
