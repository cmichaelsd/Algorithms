#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void printLinkedList(node_t* head) {
    node_t* ptr = head;

    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void addNode(node_t ** head, int data) {
    node_t* link = (node_t*) malloc(sizeof(node_t));

    link->data = data;
    link->next = *head;

    *head = link;
}

void addNodes(node_t** head, int data[], size_t data_count) {
    for (int i = 0; i < data_count; ++i) {
        addNode(head, data[i]);
    }
}

int deleteNode(node_t* head, int data) {
    node_t* current = head;
    node_t* previous = NULL;

    if (head == NULL) {
        return -1;
    }

    if (current->data == data) {
        int value = head->data;

        head = current->next;
        free(current);

        return value;
    }

    while (current != NULL) {
        if (current->data == data) {
            int value = current->data;

            previous->next = current->next;
            free(current);

            return value;
        }

        previous = current;
        current = current->next;
    }

    return -1;
}

#endif