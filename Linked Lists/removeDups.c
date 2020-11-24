#include <stdio.h>
#include "linkedList.h"

// struct node* removeDups() {

// }

/**
 * Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you do this if a temporary buffer is not allowed?
 */
int main() {
    node_t * head = (node_t *) malloc(sizeof(node_t));

    int data[] = {1,2,3,4,5,6,7,8,9};
    addNodes(&head, data, 9);
    deleteNode(head, 8);
    printLinkedList(head);
    return 0;
}