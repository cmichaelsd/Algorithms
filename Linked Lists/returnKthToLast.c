#include <stdio.h>
#include "linkedList.h"

/**
 * Time: O()
 * Space: O()
 */
int returnKthToLast(node_t* head, int k) {
    if (head == NULL) {
        return 0;
    }

    int index = returnKthToLast(head->next, k) + 1;
    if (index == k) {
        printf("The %d to last element is %d\n", k, head->data);
    }

    return index;
}

/**
 * Implement an algorithm to find the kth to last element of
 * a singly linked list.
 */
int main() {
    node_t* head = NULL;
    int data[] = {1,6,7,8,9};
    size_t data_count = sizeof(data) / sizeof(int);

    addNodes(&head, data, data_count);
    returnKthToLast(head, 2);
    printLinkedList(head);

    free(head);
    return 0;
}