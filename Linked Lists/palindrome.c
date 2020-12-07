#include <stdio.h>
#include "linkedList.h"

/**
 * Time: O(n) 
 * Space: O(n) 
 * Checks to see if a linked list is a palindrome. 
 * 
 * @param node_t* head 
 * @return int 
 */
int palindrome(node_t* head) {
    if (head == NULL) {
        return 0;
    }

    node_t* current = head;
    int length = getLength(head);
    int arr[length];

    for (int i = 0; current != NULL; ++i, current = current->next) {
        arr[i] = current->data;
    }

    int lastIndex = length - 1;
    for (int i = 0; i < (length / 2); ++i, --lastIndex) {
        if (arr[i] != arr[lastIndex]) {
            return 0;
        }
    }
    
    return 1;
}

/**
 * Implement a function to check if a linked list is a palindrome. 
 */
int main() {
    node_t* head = NULL;
    int data[] = {1,2,3,2,1};
    int data_count = sizeof(data) / sizeof(int);

    addNodes(&head, data, data_count);

    printLinkedList(head);
    printf("\n\n");

    printf("%d\n", palindrome(head));

    freeLinkedList(head);
    return 0;
}