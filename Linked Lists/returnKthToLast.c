#include <stdio.h>
#include "linkedList.h"

/**
 * Time: O()
 * Space: O()
 */
node_t* returnKthToLast(node_t* head, int k) {

}

/**
 * Implement an algorithm to find the kth to last element of
 * a singly linked list.
 */
int main() {
    node_t* head = (node_t*) malloc(sizeof(node_t));
    int data[] = {1,2,3,4,5,6,7,8,9};
    size_t data_count = sizeof(data) / sizeof(int);

    addNodes(&head, data, data_count);
    returnKthToLast(head, 3);
    printLinkedList(head);

    free(head);
    return 0;
}