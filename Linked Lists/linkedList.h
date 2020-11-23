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

struct node* deleteNode(int position) {
    struct node* current = head;
    struct node* previous = NULL;
    int iterations = 0;

    if (head == NULL) {
        return NULL;
    }

    if (position == 0) {
        head = head->next;
        return current;
    }

    while (position != iterations) {
        if (current->next == NULL) {
            return NULL;
        } else {
            previous = current;
            current = current->next;
            ++iterations;
        }
    }

    previous->next = current->next;

    return current;
}

#endif