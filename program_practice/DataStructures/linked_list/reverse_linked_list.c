#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} ll_node_t;

ll_node_t * head = NULL;
ll_node_t * temp = NULL;

void add_value_to_ll (int value) {
	ll_node_t * newnode = (ll_node_t *) malloc(sizeof(ll_node_t));
	newnode->data = value;
	newnode->next =  NULL;

	if (head == NULL) {
		head =  temp = newnode;
	} else {
		temp->next =  newnode;
		temp = newnode;
	}
}

void print_elements() {
	ll_node_t * tmp1 = head;
	while (tmp1 != NULL) {
		printf("%d ", tmp1->data);
		tmp1 = tmp1->next;
	}
	printf("\n");
}

void reverse_the_list() {
	/* How can we do:
	 * let's traverse from begin.
	 * curr_node = head then next_node = curr_node->next.
	 * prev_node = curr_node and curr = next. loop it till curr becomes NULL.
	 * Assign head to prev_node.
	 */

	ll_node_t * prev_node = NULL, * next_node = NULL, *curr_node = NULL;
	
	curr_node =  head; //1000
	while (curr_node != NULL) {
		next_node = curr_node->next;	//1004 1008 1012 NULL
		curr_node->next = prev_node;	//NULL 1000 1004 1008
		prev_node = curr_node;		//1000 1004 1008 1012
		curr_node = next_node;		//1004 1008 1012 NULL
	}
	head = prev_node; //1012
}

int main() {
	int num = 0;
	int val = 0;

	printf("Enter the number of elements : \n");
	scanf("%d", &num);

	while (num > 0) {
		printf("Enter the value : \n");
		scanf("%d", &val);
		add_value_to_ll(val);
		num--;
	}
	print_elements();
	reverse_the_list();
	print_elements();
}

/* Output:
 Enter the number of elements : 
4
Enter the value : 
2
Enter the value : 
4
Enter the value : 
5
Enter the value : 
1
2 4 5 1 
1 5 4 2
*/
