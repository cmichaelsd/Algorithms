#include <stdio.h>
#include "helpers.h"

/**
 * O(n)
 */
int oneAwayReplace(char s1[], char s2[], int count) {
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        if (s1[i] != s2[i]) {
            ++sum;
        }
        if (sum > 1) {
            return 0;
        }
    }

    return 1;
}

/**
 * O(n)
 */
int oneAwayInsert(char longer[], char shorter[], int shorter_count) {
    int sum = 0;
    for (int i = 0; i < shorter_count; ++i) {
        // popopop
        // opopop  -> true insert at index 0
        // pples
        // apples
        if ((shorter[i] != longer[i]) && (shorter[i] == longer[i+1])) {
            ++sum;
        }
        if (sum > 1) {
            return 0;
        }
    }

    return 1;
}

/**
 * O(n)
 * n = Length of both string beign equal || Length of shortest
 * 
 */
int oneAway(char s1[], int s1_count, char s2[], int s2_count) {
    /**
     * Operate depending on string length
     * If equal must be a character or none apart
     * If lengths different must be an insert apart
     */
    if (s1_count == s2_count) {
        return oneAwayReplace(s1, s2, s1_count);
    }

    if (s1_count - 1 == s2_count) {
        return oneAwayInsert(s1, s2, s2_count);
    }

    if (s1_count == s2_count - 1) {
        return oneAwayInsert(s2, s1, s1_count);
    }

    /**
     * Base case if all false
     */
    return 0;
}

/**
 * There are three types of edits that can be performed on strings: 
 * insert a characer, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit
 * (or zero edits) away.
 */
int main() {
    char s1[] = "cats";
    char s2[] = "cat";
    int s1_count = sizeof(s1) / sizeof(char);
    int s2_count = sizeof(s2) / sizeof(char);
    printf("%d\n", oneAway(s1, s1_count, s2, s2_count));
    return 0;
}