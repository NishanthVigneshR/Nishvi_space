#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node * next;
}single_ll_node;

single_ll_node *head = NULL;
single_ll_node *temp = NULL;

void add_element_to_ll (int val) {
	single_ll_node *newnode = NULL;
	single_ll_node * prev = NULL;

	newnode = (single_ll_node *) malloc(sizeof(single_ll_node));
	newnode->value = val;
	newnode->next = head;

	if (head == NULL) {
		head = temp = newnode;
		head->next = temp;
	} else {
		temp->next = newnode;
		temp = newnode;
	}
}

void print_elements_in_ll() {
	temp = head;
	int i = 0;

	for (i= 0; i < 10;i++) {
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

int main() {
	single_ll_node *newnode =NULL;
	int input = 0;
	int choice = 0;

	while (1) {
		printf("\nChoose the choice.\n[1] For adding element to LL,\n[2] For printing all the elements in LL,\n[3] For updating the element of the specific node,\n[4] For printing element present in specific node\n");
		scanf("%d", &choice);
		switch (choice) {
		    case 1:
			    printf("Enter the number to be added\n");
			    scanf("%d", &input);
			    add_element_to_ll(input);
			    break;
		    case 2:
			    print_elements_in_ll();
			    break;
		    case 3:
			    break;
		    case 4:
			    break;
		    default:
			    break;
		}
	}
}

