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
	single_ll_node *temp1 = NULL;
	temp1 = head;
	int i = 0;

	printf("Printing the Values present in LL\n");

	do {
		printf("%d ", temp1->value);
		temp1 = temp1->next;
	} while (temp1 != head);
}

void update_the_specific_node (int node, int val) {
	single_ll_node * temp1 = NULL;
	temp1 = head;
	while (node > 1) {
		temp1 = temp1->next;
		node--;
	}
	temp1->value = val;
}

void print_specific_node (int node) {
	single_ll_node * temp1 = NULL;
	temp1 = head;

	while (node > 1) {
		temp1 = temp1->next;
		node--;
	}
	printf("\n%d is the value present in this node\n", temp1->value);
}

int main() {
	single_ll_node *newnode =NULL;
	int input = 0;
	int choice = 0;
	int node = 0;

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
			    printf("Enter the node which needs to be updated\n");
			    scanf("%d", &node);
			    printf("Enter the value which should be filled\n");
			    scanf("%d", &input);
			    update_the_specific_node (node, input);
			    break;
		    case 4:
			    printf("Enter the node whose value need to be printed\n");
			    scanf("%d", &node);
			    print_specific_node(node);
			    break;
		    default:
			    break;
		}
	}
}

