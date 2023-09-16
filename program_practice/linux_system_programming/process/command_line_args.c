#include <stdio.h>

/* argc represents number of inputs provided to main function in runtime.
 * argc represents the parameter which holds the input provided during runtime.
 * (E.g) :- ./obj_file Hello! Keep up the good work.
 * 	argc will be 7.
 * 	argv will be ./obj_file Hello! Keep up the good work.
 */
int main(int argc, char *argv[]) {
	int count = 0;
	printf("Received args holding %d words\n", argc);
	while (count < argc) {
		printf("%d word : %s\n", count, argv[count]);
		count++;
	}
	/* Output:
	 * [root@localhost process]# ./command_line_args Hello! dude best of luck
	 * Received args holding 6 words
	 * 0 word : ./command_line_args
	 * 1 word : Hello!
	 * 2 word : dude
	 * 3 word : best
	 * 4 word : of
	 * 5 word : luck
	 */
}
