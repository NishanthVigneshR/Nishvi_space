#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} stack_node;

int isempty();

stack_node *top = NULL;
stack_node *temp = NULL;

void push (int val) {
	stack_node * newnode = NULL;
	newnode = (stack_node *) malloc (sizeof(stack_node));
	newnode->data = val;
	newnode->next = top;
	top = newnode;
}

void pop () {
	stack_node * temp = NULL;
	if (isempty() == 0) {
	    printf("popped data : %d\n", top->data);
	    temp = top;
	    top = top->next;
	    free(temp);
	}
	printf("\n");
}
void peek() {
	if (isempty() == 0)
		printf("Peeked : %d\n", top->data);
}

int isempty() {
	if (top == NULL)
		return 1;
	return 0;
}

int main() {
	int value;
	int ch;
	int ret = 0;

	while (1) {
		printf("\nPlease enter\n(1) for pushing the element\n(2) for popping the element\n(3) for peeking\n(4) for checking whether the stack is empty\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1:
				printf("Please enter the input\n");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
				printf("Printing the elements\n");
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				ret = isempty();
				if (ret == 1)
					printf("stack is empty\n");
				else
					printf("stack is not empty\n");
				break;
			default:
				break;
		}
	}
}
