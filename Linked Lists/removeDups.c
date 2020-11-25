#include <stdio.h>
#include "linkedList.h"

/**
 * Time: O(n)
 * Space: O(n)
 */
void removeDups(node_t** head) {
    int bitVector = 0;
    node_t* current = *head;

    if (current == NULL) {
        return;
    }

    int mask = 1 << current->data;
    bitVector |= mask;

    while (current->next != NULL) {
        mask = 1 << current->next->data;
        if ((bitVector & mask) != 0) {
            node_t* deletedNode = current->next;
            current->next = current->next->next;
            free(deletedNode);
        } else {
            bitVector |= mask;
            current = current->next;
        }
    }
}

/**
 * Time: O(n^2)
 * Space: O(c)
 */
void removeDupsNoBuffer(node_t** head) {
    node_t* current = *head;

    if (current == NULL) {
        return;
    }

    while (current != NULL) {
        node_t* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                node_t* deletedNode = runner->next;
                runner->next = runner->next->next;
                free(deletedNode);
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}

/**
 * Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you do this if a temporary buffer is not allowed?
 */
int main() {
    node_t* head = (node_t*) malloc(sizeof(node_t));

    int data[] = {0,1,1,1,14,5,1};
    size_t data_count = sizeof(data) / sizeof(int);
    addNodes(&head, data, data_count);
    removeDups(&head);
    printLinkedList(head);

    free(head);
    return 0;
}