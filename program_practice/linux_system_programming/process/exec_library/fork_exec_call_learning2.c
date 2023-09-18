#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
	int count = 0;
	printf("This is program-2 and my pid is %d\n", getpid());
	for (count = 0;count < argc; count++) {
		printf("%s\n", argv[count]);
	}
}
