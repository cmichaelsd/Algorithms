#include <stdio.h>
#include "helpers.h"

/**
 * O(n)
 * Very similar to isUnique 
 * 
 * Build a poor mans Hash Table for all ASCII values at the character code
 * Increment the count at the character codes index in the Hash Table for string one
 * Decrement the count at the character codes index in the Hash Table for string two
 * If at the end of this process the Hash Table has 0 for very index the strings are permutations of each other
 */
int checkPermutation(char s1[], char s2[], int size) {
    int arr[ASCII_CHAR_EXTENDED];
    fill(arr, ASCII_CHAR_EXTENDED, 0);

    for (int i = 0; i < size; ++i) {
        ++arr[s1[i]];
        --arr[s2[i]];
    }

    return every(arr, ASCII_CHAR_EXTENDED, 0);
}

/**
 * O(n)
 * Give two strings, write a method to decide if one is a permutation of the other.
 * 
 * I'm assuming both strings are the same length becuase the prompt did not ask
 * if the permutation is a substring of the other
 */
int main() {
    char s1[] = "abdb";
    char s2[] = "bbda";
    int size = sizeof(s1) / sizeof(char);
    printf("%d\n", checkPermutation(s1, s2, size));
    return 0;
}