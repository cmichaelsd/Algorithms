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

    if (head == NULL) {
        return;
    }

    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void addNode(node_t** head, int data) {
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

#endif