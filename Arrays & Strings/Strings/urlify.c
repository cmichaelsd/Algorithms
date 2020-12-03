#include <stdio.h>
#include "helpers.h"

/**
 * Time: O(n) 
 * Space: O(c) 
 * n = Length of string. 
 * Replaces all space characters in a character array with %20. 
 * 
 * @param char[] s 
 * @param size_t s_count 
 */
void urlify(char s[], size_t s_count) {
    int spaces = char_count(s, s_count, ' ');
    int total = s_count + (spaces * 2);

    /**
     * Working back from string size
     */
    for (int i = s_count - 1; i >= 0; --i) {
        /**
         * If element is a space
         */
        if (s[i] == ' ') {
            /**
             * Set last three indices to %, 2, 0
             * Subtract 3 from total
             */
            s[total-1] = '0';
            s[total-2] = '2';
            s[total-3] = '%';
            total -= 3;
        } else {
            /**
             * Otherwise
             * Overwrite end of the string with current character
             */
            s[total-1] = s[i];
            --total;
        }
    }
}

/**
 * Write a method to replace all spaces in a string with '%20'. You may assume that 
 * the string has sufficient space at the end to hold the additional characters, and 
 * that you are given the "true" length of the string. (Note: If implementing in Java, 
 * please use a character array so that you can perform this operation in place.)
 * EXAMPLE
 * Input:  "Mr John Smith    ", 13
 * Output: "Mr%20John%20Smith"
 */
int main() {
    char s[] = "Mr John Smith    ";
    size_t size = 13;
    urlify(s, size);
    printf("%s\n", s);
    return 0;
}