#include <stdio.h>
#include "linkedList.h"

/**
 * Time: O(a + b) 
 * Space: O(c) 
 * If two linked lists intesect the intersecting node is returned. 
 * 
 * @param node_t* headOne 
 * @param node_t* headTwo 
 * @return node_t* 
 */
node_t* intersection(node_t* headOne, node_t* headTwo) {
    if (headOne == NULL || headTwo == NULL) {
        return NULL;
    }

    /* Get list lengths */
    int headOneLength = getLength(headOne);
    int headTwoLength = getLength(headTwo);

    /* Dynamically set list lengths */
    int longestLength = (headOneLength > headTwoLength) ? headOneLength : headTwoLength;
    int smallestLength = (headTwoLength < headOneLength) ? headTwoLength : headOneLength;

    /* Dynamically set lists and node pointers */
    node_t* longestList = (headOneLength > headTwoLength) ? headOne : headTwo;
    node_t* smallestList = (headTwoLength < headOneLength) ? headTwo : headOne;
    node_t* longestCurrent = longestList;
    node_t* smallestCurrent = smallestList;

    /* Move longest list node pointer forward the difference in list lengths */
    int i = longestLength - smallestLength;
    while (i > 0) {
        longestCurrent = longestCurrent->next;

        --i;
    }

    /* Both lengths are now same iterate a given list */
    while (smallestCurrent != NULL) {
        if (longestCurrent == smallestCurrent) {
            return smallestCurrent;
        }

        longestCurrent = longestCurrent->next;
        smallestCurrent = smallestCurrent->next;
    }

    return NULL;
}

/**
 * Given two (singly) linked lists, determine if the two lists intersect.
 * Return the intersecting node. Note that the intersection is defined based on reference,
 * not value. That is, if the kth node of the first linked list is the exact same node (by reference)
 * as the jth node of the second linked list, then they are intersecting.
 */
int main() {
    node_t* headOne = NULL;
    node_t* headTwo = NULL;
    int data_one[] = {1,2,3,4,5,6};
    int data_two[] = {2,8,9,0};
    int data_one_count = sizeof(data_one) / sizeof(int);
    int data_two_count = sizeof(data_two) / sizeof(int);

    addNodes(&headOne, data_one, data_one_count);
    addNodes(&headTwo, data_two, data_two_count);

    node_t* nNodeOne = getNthNode(headOne, 3);
    node_t* tailTwo = getTail(&headTwo);

    tailTwo->next = nNodeOne;

    node_t* intersect = intersection(headOne, headTwo);

    if (intersect != NULL) {
        printf("%d\n", intersect->data);
    }

    return 0;
}