#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

typedef struct single_ll_node {
	int value;
	struct single_node * next;
} single_ll_node_t;

typedef struct double_ll_node {
	int value;
	struct double_ll_node * prev;
	struct double_ll_node * next;
} double_ll_node_t;
#endif /* _LINKED_LIST_H_ */
