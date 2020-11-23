#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node* next;
    int data;
};

struct node* head = NULL;

void printLinkedList() {
    struct node* ptr = head;

    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void addNode(int data) {
    struct node* link = (struct node*) malloc(sizeof(struct node));

    link->data = data;
    link->next = head;

    head = link;
}

struct node* deleteNode(int data) {
    struct node* current = head;

    if (head == NULL) {
        return NULL;
    }

    if (current->data == data) {
        head = current->next;

        return head;
    }

    while (current->next != NULL) {
        if (current->next->data == data)  {
            current->next = current->next->next;

            return head;
        }
        current = current->next;
    }

    return head;
}

#endif