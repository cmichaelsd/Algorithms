#include <stdio.h>
#include <string.h>
#include "helpers.h"

/**
 * Time: O(n)
 * Space: O(n * 2)
 * 
 * n = s1_count
 */
int stringRotation(char s1[], char s2[], size_t s1_count, size_t s2_count) {
    /* If strings are different lengths, return 0. */
    if (s1_count != s2_count) {
        return 0;
    }

    /* Repeat the string */
    size_t repeated_s1_count = s1_count * 2;
    char repeated_s1[repeated_s1_count];
    strcpy(repeated_s1, s1);
    strcat(repeated_s1, s1);

    /* If  s2 exists in the repeated_s1 then it is a substring */
    if (isSubstring(repeated_s1, s2, repeated_s1_count, s2_count) != -1) {
        return 1;
    }

    return 0;
}

/**
 * Assume you have a method isSubstring which checks if one word is a substring
 * of another. Given two strings, s1 and s2, write code to check if s2 is a rotation
 * of s1 using only one call to isSubstring (e.g., "waterbottle" is a rotation of "erbottlewat").
 */
int main() {
    char s1[] = "waterbottle";
    size_t s1_count = 12;
    char s2[] = "erbottlewat";
    size_t s2_count = 12;

    printf("%d\n", stringRotation(s1, s2, s1_count, s2_count));

    return 0;
}