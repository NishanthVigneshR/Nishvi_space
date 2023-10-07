#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node * prev;
	struct node * next;
} double_node_t;

double_node_t *head = NULL;
double_node_t *temp = NULL;

void add_element_to_list (char val) {
	double_node_t *newnode = NULL;

	newnode = (double_node_t *) malloc(sizeof(double_node_t));
	newnode->prev = temp;
	newnode->data = val;
	newnode->next = head;

	if (head == NULL) {
		head = temp = newnode;
	} else {
		temp->next = newnode;
	}
	head->prev = newnode;
	temp = newnode;
	printf("%c added to list\n", val);
}

void print_all_elements () {
	double_node_t *t1 = NULL;
	t1 = head;

	if (t1 == NULL)
		return;
	printf("Printing the elements in list\n");
	do {
		printf("%c", t1->data);
		t1 = t1->next;
	} while (t1 != head);
	printf("\n");
}

void print_specific_node(int node) {
	double_node_t *t1 = NULL;
	t1 = head;
	while (node > 1) {
		t1 = t1->next;
		node--;
	}
	printf("Current value is %c\n", t1->data);
	printf("Previous value is %c\n", (t1->prev)->data);
	printf("Next value is %c\n", (t1->next)->data);
}

void delete_specific_node(int node) {
	double_node_t *t1 = NULL;
	t1 = head;
	if (node == 1)
		head = t1->next;
	while (node > 1) {
                t1 = t1->next;
                node--;
        }
	(t1->prev)->next = t1->next;
	free(t1);
}

void delete_specific_value(char input) {
	double_node_t *t1 = NULL;
        t1 = head;
	if (t1->data == input) {
            (t1->prev)->next = t1->next;
	    head = t1->next;
	    free(t1);
	    return;
	}
	t1 = t1->next;
	while (t1 != head) {
            if (t1->data == input) {
                (t1->prev)->next = t1->next;
                free(t1);
                return;
	    }
	}
	printf("value not found\n");
}

int main() {
	char value[20] = {'\0'};
	int ch = 0;
	int i = 0;
	int node = 0;
	char val;

	while (1) {
		printf("Enter\n(1) For adding element to list\n(2) For printing all the present elements\n(3) For printing specific node\n(4) For deleting the specific node\n(5) For deleting specific value\n");
		scanf("%d", &ch);

		switch(ch) {
			case 1:
				printf("Enter the string to be added\n");
				scanf("%s", value);
				//fgets(value, sizeof(value), stdin);
				while (value[i] != '\0') {
					add_element_to_list(value[i]);
					i++;
				}
				break;
			case 2:
				print_all_elements();
				break;
			case 3:
				printf("Enter the specific node to be printed\n");
				scanf("%d", &node);
				print_specific_node(node);
				break;
			case 4:
				printf("Enter the node to be deleted\n");
				scanf("%d", &node);
				delete_specific_node(node);
				break;
			case 5:
				printf("Delete specific value");
				scanf(" %c", &val);
				delete_specific_value(val);
				break;
			default:
				break;
		}
	}
}
