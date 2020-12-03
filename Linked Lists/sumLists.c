#include <stdio.h>
#include "linkedList.h"

/**
 * Time: O(n) 
 * Space: O(n)
 * Returns a linked list which is the sum of headOne and headTwos nodes. 
 * 
 * @param node_t* headOne
 * @param node_t* headTwo
 * @return node_t*
 */
node_t* sumListsNewList(node_t* headOne, node_t* headTwo) {
    if (headOne == NULL || headTwo == NULL) {
        return NULL;
    }

    node_t* headOneCurrent = headOne;
    node_t* headTwoCurrent = headTwo;
    node_t* sumHead = (node_t*) malloc(sizeof(node_t));
    node_t* sumCurrent = sumHead;
    int carry = 0;

    while ((headOneCurrent != NULL) || (headTwoCurrent != NULL)) {
        node_t* n = (node_t*) malloc(sizeof(node_t));
        int value = carry;
        carry = 0;

        if (headOneCurrent != NULL) {
            value += headOneCurrent->data;
            headOneCurrent = headOneCurrent->next;
        }

        if (headTwoCurrent != NULL) {
            value += headTwoCurrent->data;
            headTwoCurrent = headTwoCurrent->next;
        }

        if (value >= 10) {
            carry = 1;
            value -= 10;
        }

        sumCurrent->data = value;
        sumCurrent->next = n;

        sumCurrent = sumCurrent->next;
    }

    return sumHead;
}

/**
 * Time: O(m) 
 * Space: O(m - n) 
 * Creates a linked list which is the sum of headOne and headTwos nodes. headOne 
 * is used as the new summed linked list. 
 * 
 * m = length of longest list. 
 * n = length of shorter list. 
 * 
 * If list m is 6 and list n is 3, I will in the worst case
 * scenario create 3 more nodes.
 * 
 * @param node_t* headOne
 * @param node_t* headTwo
 */
void sumLists(node_t* headOne, node_t* headTwo) {
    if (headOne == NULL || headTwo == NULL) {
        return;
    }

    node_t* headOneCurrent = headOne;
    node_t* headTwoCurrent = headTwo;
    int carry = 0;

    /* If main list still has a node */
    while (headOneCurrent != NULL) {

        int value = carry + headOneCurrent->data;
        carry = 0;

        /**
         * Since headTwoCurrent node exists add value to total.
         * Update headTwoCurrent to next.
         */
        if (headTwoCurrent != NULL) {
            value += headTwoCurrent->data;
            headTwoCurrent = headTwoCurrent->next;
        }

        if (value >= 10) {
            /**
             * Max case first round 9 + 9 = 18
             * Max case second round 1 + 9 + 9 = 19
             * Carry = 1
             * Value = 8
             */
            carry = 1;
            value -= 10;
        }

        /**
         * If headOneCurrent next is null and headTwoCurrent next is not null. 
         * Add a node to main list.
         */
        if ((headOneCurrent->next == NULL) && (headTwoCurrent != NULL)) {
            node_t* n = (node_t*) malloc(sizeof(node_t*));
            n->data = 0;
            headOneCurrent->next = n;
        }

        /**
         * Set data to value less than 10 or first decimal of value 
         * greater than or equal to 10.
         * 
         * Set headOneCurrent to next.
         */
        headOneCurrent->data = value;
        headOneCurrent = headOneCurrent->next;
    }
}

/**
 * You have two numbers represented by a linked list, where each node
 * containts a single digit. The digits are stored in reverse order, such
 * that the 1's digit is at the head of the list. Write a function that adds
 * the two numbers and returns the sum as a linked list.
 * EXAMPLE
 * Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
 * Output: 2 -> 1 -> 9. That is, 912.
 * FOLLOW UP
 * Suppose the digits are stored in forward order. Repeat the above problem.
 * Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
 * Output: 9 -> 1 -> 2. That is, 912.
 */
int main() {
    node_t* headOne = NULL;
    node_t* headTwo = NULL;

    int dataOne[] = {6,1,7};
    int dataTwo[] = {2,9,5,8};

    size_t dataOne_count = sizeof(dataOne) / sizeof(int);
    size_t dataTwo_count = sizeof(dataTwo) / sizeof(int);

    addNodes(&headOne, dataOne, dataOne_count);
    addNodes(&headTwo, dataTwo, dataTwo_count);

    printLinkedList(headOne);
    printf("\n\n");
    printLinkedList(headTwo);
    printf("\n\n");

    node_t* sumHead = sumListsNewList(headOne, headTwo);
    printf("\n\n");
    printLinkedList(sumHead);

    freeLinkedList(headOne);
    freeLinkedList(headTwo);

    return 0;
}