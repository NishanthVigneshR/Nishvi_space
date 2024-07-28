#include <stdio.h>
#include <String.h>
#include <Stdlib.h>

typedef struct double_ll_node {
	int data;
	struct double_ll_node *prev_node;
	struct double_ll_node *next_node;
} double_ll_node_t;

void add_element_to_linked_list (int value);
void print_the_values_in_node (double_ll_node_t *head);
void update_specific_index_value(int index, int value);
void print_specific_node_value(int index);
void fetch_both_the_prev_n_next_index_nodes(int index);
void remove_head_node();
void remove_specific_node (int index);

double_ll_node_t *head = NULL;
double_ll_node_t *temp = NULL;

int main() {
	int choice = 0;
	int value_to_be_added = 0;
	int index = 0;
	while (1) {
		printf("\nChoose the choice.\n[1] For adding element to LL,\n[2] For printing all the elements in LL,\n[3] For updating the element of the specific node,\n[4] For printing element present in specific node,\n[5] For fetching both prev and next node of given node,\n[6] For removing head node,\n[7] For removing specific node\n");
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
			case 5:
				printf("\nFetch both the previous and next values of the given node. Enter the node\n");
				scanf("%d", &index);
				fetch_both_the_prev_n_next_index_nodes(index);
				break;
			case 6:
				remove_head_node();
				break;
			case 7:
				printf("\nEnter the node to be removed\n");
				scanf("%d", &index);
				remove_specific_node(index);
				break;
			default:
				printf("\nPlease provide valid choice (1-4)\n");
				break;
		}
	}
}

void add_element_to_linked_list(int value) {
	double_ll_node_t *newnode = NULL;
	newnode = (double_ll_node_t *) malloc (sizeof(double_ll_node_t));
	newnode->data = value;
	newnode->next_node = NULL;
	if (head == NULL) {
		printf("\n Head is NULL\n");
		head = temp = newnode;
		newnode->prev_node = NULL;
	} else {
		temp->next_node =  newnode;
		newnode->prev_node = temp;
		temp = newnode;
	}
	printf("\n Value %d is added to DLL\n", temp->data);
}

void print_the_values_in_node (double_ll_node_t *head) {
	temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next_node;
	}
	printf("\n");
}

void update_specific_index_value(int index, int value) {
	int temp_index = 1;
	temp = head;
	while ((temp_index != index) &&
			(temp != NULL)) {
		temp = temp->next_node;
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
		temp = temp->next_node;
		temp_index++;
	}
	if (temp_index == index) {
		printf("\n The value in provided index [%d] is %d\n", index, temp->data);
	} else {
		printf("\nProvided index exceeded current linked list index\n");
	}
}

void fetch_both_the_prev_n_next_index_nodes(int index) {
	int temp_index = 1;
	temp = head;
	double_ll_node_t *temp1 = NULL;
	while ((temp_index != index) &&
			(temp != NULL)) {
		temp = temp->next_node;
		temp_index++;
	}
	if (temp_index == index) {
		temp1 = temp->prev_node;
		if (temp1 == NULL) {
		    printf("\nPrevious node is NULL\n");
	    } else {
	    	printf("\nPrevious node of given node is holding value %d\n", temp1->data);
		}
		temp1 =  temp->next_node;
		if (temp1 == NULL) {
		    printf("\nNext node is NULL\n");
	    } else {
	    	printf("\nNext node of given node is holding value %d\n", temp1->data);
		}
	} else {
		printf("\nProvided index exceeded current linked list index\n");
	}
}

void remove_head_node () {
	temp = head;
	temp = temp->next_node;
	head = temp;
	printf("\nHead node removed. Now, the value is head is %d\n", head->data);
}

void remove_specific_node (int index) {
	temp = head;
	int temp_index = 1;
	double_ll_node_t *prev_node_t = NULL;
	while ((temp_index != index) &&
			(temp != NULL)) {
				temp = temp->next_node;
				temp_index++;
			}
	if (temp_index == index) {
		printf("\nRemoving node with value %d\n", temp->data);
		prev_node_t = temp->prev_node;
		if (prev_node_t ==  NULL)
			remove_head_node();
		else {
			prev_node_t->next_node = temp->next_node;
		    free (temp);	
		}
		
	} else {
		printf("\nProvided index exceeded current linked list index\n");
	}
}
