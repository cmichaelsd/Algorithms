#include <stdio.h>
#include "linkedList.h"

/**
 * Time: O(n) 
 * Space: O(c) 
 * If a linked list is circular the corrputed node is returned. 
 * 
 * @param node_t* head
 * @return node_t*
 */
node_t* loopDetection(node_t* head) {
    /**
     * () = looped node
     * [] = collision node
     * 
     * [(1)] -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> [(1)]
     * 
     * 1 -> (2) -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> [9] -> (2)
     * 
     * 1 -> 2 -> (3) -> 4 -> 5 -> 6 -> 7 -> [8] -> 9 -> (3)
     * 
     * ...
     * 
     * The looped node will always be moving from head and collision node until 
     * both pointers equal same node.
     */
    if (head == NULL) {
        return NULL;
    }

    node_t* fast = head;
    node_t* slow = head;

    while ((fast != NULL) && (fast->next != NULL)) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            break;
        }
    }

    if ((fast == NULL) || (fast->next == NULL)) {
        return NULL;
    }

    slow = head;

    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}

/**
 * Given a circular linked list, implement an algorithm that returns the node at the
 * beginning of the loop. 
 * DEFINITION
 * Circular linked list: A (corrupt) linked list in which a node's next pointer points 
 * to and ealier node, so as to make a loop in the linked list. 
 * EXAMPLE
 * Input:  A -> B -> C -> D -> E -> C [the same C as ealier]
 * Output: C
 */
int main() {
    int data[] = {1,2,3,4,5,6};
    int data_count = sizeof(data) / sizeof(int);
    node_t* head = NULL;

    addNodes(&head, data, data_count);

    node_t* tail = getTail(&head);
    node_t* nNode = getNthNode(head, 3);

    tail->next = nNode;

    node_t* loopedNode = loopDetection(head);

    printf("%d\n", loopedNode->data);

    return 0;
}