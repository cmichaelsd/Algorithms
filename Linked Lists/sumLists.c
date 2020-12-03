#include <stdio.h>
#include "linkedList.h"

/**
 * Time: O(m)
 * Space: O(m - n)
 * 
 * m = length of longest list
 * n = length of shorter list
 * 
 * If list m is 6 and list n is 3, I will in the worst case
 * scenario create 3 more nodes.
 */
void sumLists(node_t* headOne, node_t* headTwo) {
    node_t* headOneCurrent = headOne;
    node_t* headTwoCurrent = headTwo;
    int carry = 0;

    /* If main list still has a node */
    while (headOneCurrent != NULL) {
        /**
         * Issue: If number is greater than or equal to 10 I need to
         * getDecimal for number and set to current node. removeDecimal.
         * getDecimal for number and add to next node if node exists. 
         * Else set as data for new node and set node as next 
         */

        int value = carry + headOneCurrent->data;
        carry = 0;

        /**
         * Since headTwoCurrent node exists add value to total.
         * Update headTwoCurrent to enxt.
         */
        if (headTwoCurrent != NULL) {
            value += headTwoCurrent->data;
            headTwoCurrent = headTwoCurrent->next;
        }

        if (value >= 10) {
            /**
             * Max case 9 + 9 = 18
             * Carry = 1
             * Value = 8
             */
            carry = 1;
            value = value - 10;
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

    int dataOne[] = {2,6,1,7,8};
    int dataTwo[] = {2,9,5};

    size_t dataOne_count = sizeof(dataOne) / sizeof(int);
    size_t dataTwo_count = sizeof(dataTwo) / sizeof(int);

    addNodes(&headOne, dataOne, dataOne_count);
    addNodes(&headTwo, dataTwo, dataTwo_count);

    printLinkedList(headOne);
    printf("\n\n");
    printLinkedList(headTwo);
    printf("\n\n");

    sumLists(headOne, headTwo);

    printLinkedList(headOne);
    // printLinkedList(headTwo);
}