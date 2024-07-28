#include <stdio.h>
#include <stdlib.h>

typedef struct single_ll_node {
	int data;
	struct single_ll_node *next;
} single_ll_node_t;

void add_element_to_linked_list (int value);
void print_the_values_in_node (single_ll_node_t *head);
void update_specific_index_value(int index, int value);
void print_specific_node_value(int index);

single_ll_node_t *head = NULL;
single_ll_node_t *temp = NULL;

int main() {
	int choice = 0;
	int value_to_be_added = 0;
	int index = 0;
	while (1) {
		printf("\nChoose the choice.\n[1] For adding element to LL,\n[2] For printing all the elements in LL,\n[3] For updating the element of the specific node,\n[4] For printing element present in specific node\n");
		scanf("%d", &choice);
	    switch (choice) {
		    case 1:
				printf("\nEnter the element to be added to linked list\n");
				scanf("%d", &value_to_be_added);
				add_element_to_linked_list(value_to_be_added);
				break;
			case 2:
				printf("\nPrint all the values in linked list\n");
				print_the_values_in_node(head);
				break;
			case 3:
				printf("\nReplace the value of specific node in mentioned index.\nEnter the index to be updated and value\n");
				scanf("%d %d", &index, &value_to_be_added);
				update_specific_index_value(index, value_to_be_added);
				break;
			case 4:
				printf("\nPrint the value in specific node\n");
				scanf("%d", &index);
				print_specific_node_value(index);
				break;
			default:
				printf("\nPlease provide valid choice (1-4)\n");
				break;
	    }
    }
}
void add_element_to_linked_list (int value) {
	single_ll_node_t *newnode = NULL;
	newnode = (single_ll_node_t *) malloc (sizeof(single_ll_node_t));
	newnode->data = value;
	newnode->next = NULL;
	
	if (head == NULL) {
		printf("\n Head is NULL\n");
		head = temp = newnode;
	} else {
		temp->next = newnode;
		temp = newnode;
	}
	printf("\n Value %d is added to Linked list\n", temp->data);
}

void print_the_values_in_node (single_ll_node_t *head) {
	temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void update_specific_index_value(int index, int value) {
	int temp_index = 1;
	temp = head;
	while ((temp_index != index) &&
			(temp != NULL)) {
		temp = temp->next;
		temp_index++;
	}
	if (temp_index == index) {
		printf("\nCurrent Value in index[%d] is %d, Replacing it with %d\n", index, temp->data, value);
		temp->data = value;
	} else {
		printf("\nCouldn't able to update LL, Provided index exceeded current linked list index\n");
	}
	
}

void print_specific_node_value(int index) {
	int temp_index = 1;
	temp = head;
	while ((temp_index != index) &&
			(temp != NULL)) {
		temp = temp->next;
		temp_index++;
	}
	if (temp_index == index) {
		printf("\n The value in provided index [%d] is %d\n", index, temp->data);
	} else {
		printf("\nProvided index exceeded current linked list index\n");
	}
}

