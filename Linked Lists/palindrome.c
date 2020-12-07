#include <stdio.h>
#include "linkedList.h"

/**
 * Time: O() 
 * Space: O() 
 * 
 * @param node_t* head 
 * @return int 
 */
int palindrome(node_t* head) {

}

/**
 * Implement a function to check if a linked list is a palindrome.
 */
int main() {
    node_t* head = NULL;
    int data[] = {1,1,2,2,1};
    int data_count = sizeof(data) / sizeof(int);

    addNodes(&head, data, data_count);

    printf("%d\n", palindrome(head));

    freeLinkedList(head);
    return 0;
}