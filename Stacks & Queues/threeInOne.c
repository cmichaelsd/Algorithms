#include <stdio.h>
#include "stack.h"

/**
 * Describe how you could use a single array to implement three stacks.
 */
int main() {
	node_t* top = NULL;
	push(&top, 1);
	
	printf("Here: %d\n", pop(&top));

	return 0;
}