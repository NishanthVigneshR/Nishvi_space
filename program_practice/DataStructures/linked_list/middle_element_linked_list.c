#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} list_node_t;

list_node_t * head = NULL;
list_node_t * temp = NULL;

void add_element_to_list (int value) {
	list_node_t * newnode = (list_node_t *) malloc (sizeof(list_node_t));
	newnode->data = value;
	newnode->next = NULL;

	if (head == NULL) {
		head = temp = newnode;
	} else {
		temp->next = newnode;
		temp = newnode;
	}
}

void fetch_list_middle_element() {
	list_node_t * temp2 = NULL;
	temp = temp2 = head;

	while ((temp2 != NULL) &&
		(temp2->next != NULL)) {
		printf("looping\n");
		temp = temp->next;
		temp2 = temp2->next;
		if(temp2 != NULL) {
			temp2 = temp2->next;
		}
	}
	printf("Middle element is %d\n", temp->data);
}

int main() {
	int val = 0;
	while (1) {
		printf("Enter the Value to be added to list, Enter 0 to exit the value add loop\n");
		scanf("%d", &val);
		if (val == 0) {
			break;
		}
		add_element_to_list(val);
	}
	fetch_list_middle_element();
}

/* Output:
 *
 * [root@localhost DataStructures]# ./a.out
Enter the Value to be added to list, Enter 0 to exit the value add loop
1
Enter the Value to be added to list, Enter 0 to exit the value add loop
2
Enter the Value to be added to list, Enter 0 to exit the value add loop
3
Enter the Value to be added to list, Enter 0 to exit the value add loop
4
Enter the Value to be added to list, Enter 0 to exit the value add loop
5
Enter the Value to be added to list, Enter 0 to exit the value add loop
6
Enter the Value to be added to list, Enter 0 to exit the value add loop
0
looping
looping
looping
Middle element is 4
[root@localhost DataStructures]# ./a.out
Enter the Value to be added to list, Enter 0 to exit the value add loop
1
Enter the Value to be added to list, Enter 0 to exit the value add loop
2
Enter the Value to be added to list, Enter 0 to exit the value add loop
3
Enter the Value to be added to list, Enter 0 to exit the value add loop
4
Enter the Value to be added to list, Enter 0 to exit the value add loop
5
Enter the Value to be added to list, Enter 0 to exit the value add loop
0
looping
looping
Middle element is 3
*/
