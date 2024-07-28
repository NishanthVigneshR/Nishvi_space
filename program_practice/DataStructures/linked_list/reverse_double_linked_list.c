#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

double_ll_node_t * head = NULL;
double_ll_node_t * temp = NULL;

void add_value_to_double_list (int value) {
	double_ll_node_t * newnode = (double_ll_node_t *) malloc(sizeof(double_ll_node_t));

	newnode->value = value;
	newnode->next = NULL;

	if (head == NULL) {
		head = temp = newnode;
		newnode->prev = NULL;
	} else {
		newnode->prev = temp;
		temp->next = newnode;
		temp = newnode;
	}
}

void print_elements_in_double_list(double_ll_node_t * ptr) {
	double_ll_node_t * print_ptr = NULL;

	print_ptr = ptr;

	while (print_ptr != NULL) {
		printf("Value - %d\n", print_ptr->value);
		print_ptr = print_ptr->next;
	}
}

void reverse_double_ll() {
	double_ll_node_t * curr_node = NULL;
	double_ll_node_t * prev_node = NULL;
	double_ll_node_t * next_node = NULL;

	curr_node = head;

	while (curr_node != NULL) {
	    next_node = curr_node->next;
	    curr_node->next = prev_node;
	    curr_node->prev = next_node;
	    prev_node = curr_node;
	    curr_node = next_node;
	}
	head = prev_node;
}

int main() {
	int val = 0;

	while(1) {
		printf("Enter the Value (0 to exit)\n");
		scanf("%d", &val);
		if (val == 0)
			break;
		add_value_to_double_list(val);
	}

	print_elements_in_double_list(head);

	reverse_double_ll();
	printf("After list reverse\n");
	print_elements_in_double_list(head);
}
