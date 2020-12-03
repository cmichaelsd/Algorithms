#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Time: O(n) 
 * Space: O(m + n) 
 * n = Length of shortest string. 
 * m = Length of longest string. 
 * Returns 1 if character array s1 is one modification away from character array s2. 
 * 
 * @param char[] s1 
 * @param size_t s1_count 
 * @param char[] s2 
 * @param size_t s2_count 
 * @return int returns 1 if character arrays are one modification apart otherwise returns 0. 
 */
int oneAway(char s1[], size_t s1_count, char s2[], size_t s2_count) {
    /**
     * If difference in string length is greater than one
     * Return false
     */
    if (abs(s1_count - s2_count) > 1) {
        return 0;
    }

    int shorterIndex = 0;
    int longerIndex = 0;
    int difference = 0;

    /**
     * Dynamically set longer and shorter strings
     */
    char* shorter = (s1_count < s2_count) ? s1 : s2;
    char* longer = (s1_count < s2_count) ? s2 : s1;
    int shorter_count = strlen(shorter);
    int longer_count = strlen(longer);

    /**
     * 
     * shorter = at
     * longer  = cat
     * 
     * If a = c, ++longerIndex difference = 1;
     * If a = a, ++longerIndex ++shorterIndex
     * If t = t, ++longerIndex ++shorterIndex
     * 
     * shorter = cab
     * longer = cap
     * 
     * If c = c, ++longerIndex ++shorterIndex
     * If a = a, ++longerIndex ++shorterIndex
     * If b = p, ++longerIndex ++shorterIndex difference = 1;
     */
    while (shorterIndex < shorter_count && longerIndex < longer_count) {
        /**
         * If the shorter strings character does not match the
         * longer strings character incremenet the longer strings index 
         */
        if (shorter[shorterIndex] != longer[longerIndex]) {

            /* If a difference has already been found, return false */
            if (difference) {
                return 0;
            }

            difference = 1;

            /* If strings are equal length increment shorterIndex */
            if (shorter_count == longer_count) {
                ++shorterIndex;
            }
        } else {
            /* If elements are the same increment shorterIndex */
            ++shorterIndex;
        }

        /* Always increment longerIndex */
        ++longerIndex;
    }

    return 1;
}

/**
 * There are three types of edits that can be performed on strings: 
 * insert a characer, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit
 * (or zero edits) away.
 */
int main() {
    char s1[] = "caps";
    char s2[] = "cat";
    size_t s1_count = sizeof(s1) / sizeof(char);
    size_t s2_count = sizeof(s2) / sizeof(char);
    printf("%d\n", oneAway(s1, s1_count, s2, s2_count));
    return 0;
}