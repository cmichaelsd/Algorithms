#include <stdio.h>
#include "linkedList.h"

void swapNodes(node_t* nodeA, node_t* nodeB) {
    int nodeAValue = nodeA->data;
    nodeA->data = nodeB->data;
    nodeB->data = nodeAValue;
}

void partition(node_t** head, int partition) {
    node_t* lt = NULL;
    node_t* gt = NULL;
    node_t* current = *head;

    while (current != NULL) {
        if (current->data < partition) {
            addNode(&lt, current->data);
        } else {
            addNode(&gt, current->data);
        }

        current = current->next;
    }
    
    node_t* ltTail = getTail(&lt);

    if (ltTail != NULL) {
        ltTail->next = gt;
    }

    *head = lt;
}

/**
 * Write code to partition a linked list around a value x, such that
 * all nodes less than x come before all nodes greater than or equal
 * to x. If x is contained within the list, the values of x only need
 * to be after the elements less than x (see below). The partition element
 * x can appear anywhere in the "right partition"; it does not need to appear
 * between the left and right partitions.
 * EXAMPLE
 * Input:  3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
 * Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
 */
int main() {
    node_t* head = NULL;
    int data[] = {1,2,10,5,8,5,3};
    size_t data_count = sizeof(data) / sizeof(int);

    addNodes(&head, data, data_count);

    printLinkedList(head);
    printf("\n\n");
    partition(&head, 5);
    printLinkedList(head);
    
    freeLinkedList(head);
    return 0;
}