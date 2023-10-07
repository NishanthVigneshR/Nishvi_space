#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node * next;
} queue_node;

queue_node * head = NULL;
queue_node * tail = NULL;

void enqueue (char val) {
	queue_node * newnode = (queue_node *) malloc(sizeof(queue_node));

	newnode->data = val;
        newnode->next = NULL;

	if (head == NULL) {
		head = tail = newnode;
	} else {
		tail->next = newnode;
		tail = newnode;
	}
}

void dequeue() {
	queue_node * temp = NULL;

	if (head == NULL)
		return;
	temp = head;
	printf("Dequeued data : %c\n", temp->data);
	head = temp->next;
	free(temp);
}

void print_all_elements() {
	queue_node * temp = NULL;
	temp = head;
	if (temp == NULL)
		return;

	do {
		printf("%c ",temp->data);
		temp = temp->next;
	} while (temp != NULL);
	printf("\n");
}

int main() {
	char val;
	int ch;

	while (1) {
		printf("Enter\n1 - for enqueuing\n2 - for dequeuing\n3 - for printing all the elements in queue\n");
		scanf("%d", &ch);
		switch (ch) {
		    case 1:
			    printf("Please enter the data for enqueue : ");
			    scanf(" %c", &val);
			    enqueue(val);
			    break;
		    case 2:
			    dequeue();
			    break;
		    case 3:
			    print_all_elements();
			    break;
		    default:
			    break;
		}
	}
}
