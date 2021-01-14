#ifndef STACK
#define STACK
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int data;
	struct node* next;
} node_t;

/**
 * Time: O(c) 
 * Space: O(c) 
 * Pops off the top element of a stack given a top double pointer. 
 * 
 * @param node_t** top
 * @return int
 */
int pop(node_t** top) {
	if (*top == NULL) {
		return -1;
	}

	int temp = (*top)->data;
	*top = (*top)->next;

	return temp;
}

/**
 * Time: O(c) 
 * Space: O(c) 
 * Pushes a new node to a stack given a top double pointer. 
 * 
 * @param node_t** top 
 * @param int data
 */
void push(node_t** top, int data) {
	node_t* nTop = (node_t*) malloc(sizeof(node_t));

	nTop->data = data;

	if ((*top) != NULL) {
		(*top)->next = nTop;
	}

	*top = nTop;
}

/**
 * Time: O(c) 
 * Space: O(c) 
 * Peeks the top elements data in a stack given a top pointer. 
 * 
 * @param node_t* top
 * @return int
 */
int peek(node_t* top) {
	if (top == NULL) {
		return -1;
	}

	return top->data;
}

/**
 * Time: (c) 
 * Space: (c) 
 * Returns 0 if a stack is empty and a 1 if it is not. 
 * 
 * @param node_t* top
 */
int isEmpty(node_t* top) {
	return top == NULL;
}

#endif