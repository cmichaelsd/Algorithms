#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

/**
 * Time: O(n) 
 * Space: O(c) 
 * Prints each linked list nodes data property. 
 * 
 * @param node_t* head
 */
void printLinkedList(node_t* head) {
    node_t* ptr = head;

    if (head == NULL) {
        return;
    }

    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

/**
 * Time: O(c) 
 * Space: O(c) 
 * Pushes an integer into the linked list as a new node. 
 * 
 * @param node_t** head
 * @param int data
 */
void addNode(node_t** head, int data) {
    node_t* link = (node_t*) malloc(sizeof(node_t));

    link->data = data;
    link->next = *head;

    *head = link;
}

/**
 * Time: O(n) 
 * Space: O(n) 
 * Pushes each integer in the data array into the linked list as a new node. 
 * 
 * @param node_t** head
 * @param int[] data
 * @param size_t data_count
 */
void addNodes(node_t** head, int data[], size_t data_count) {
    for (int i = 0; i < data_count; ++i) {
        addNode(head, data[i]);
    }
}

/**
 * Time: O(n) 
 * Space: O(c) 
 * Removes the first node found in a linked list which has a data property equal to the data parameter. 
 * 
 * @param node_t** head
 * @param int data
 * @return int returns the data property of the node is found otherwise -1 is returned
 */
int deleteNode(node_t** head, int data) {
    node_t* current = *head;

    if (head == NULL) {
        return -1;
    }

    if (current->data == data) {
        int value = current->data;

        *head = current->next;
        free(current);

        return value;
    }

    while (current->next != NULL) {
        if (current->next->data == data) {
            int value = current->next->data;
            node_t* deletedNode = current->next;

            current->next = current->next->next;
            free(deletedNode);

            return value;
        }

        current = current->next;
    }

    return -1;
}

/**
 * Time: O(n) 
 * Space: O(c) 
 * Returns the Nth node of a linked list. 
 * 
 * @param node_t* head
 * @param int n
 * @return node_t*
 */
node_t* getNthNode(node_t* head, int n) {
    node_t* current = head;

    if (head == NULL || n < 1) {
        return NULL;
    }

    while (n > 1 && current != NULL) {
        --n;
        current = current->next;
    }

    return current;
}

/**
 * Time: O(n) 
 * Space: O(c) 
 * Iterates a linked list and frees the memory of each node. 
 * 
 * @param node_t* head
 */
void freeLinkedList(node_t* head) {
    node_t* current = head;

    if (head == NULL) {
        return;
    }

    while (current != NULL) {
        node_t* next = current->next;
        free(current);

        current = next;
    }
}

/**
 * Time: O(n) 
 * Space: O(c) 
 * Returns the tail node of a linked list. 
 * 
 * @param node_t** head
 * @return node_t*
 */
node_t* getTail(node_t** head) {
    node_t* current = *head;

    if (current == NULL) {
        return NULL;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}

#endif