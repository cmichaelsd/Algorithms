#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

/**
 * O(n)
 * 
 * n = Length of input string
 * 
 * The same number of operations occur for each element in the input string
 */
char* stringCompression(char s[], int s_count, char* result) {
    /**
     * Set first character as previous and set for loop to iterate
     * at 1. Set sum to 1 as previous character must have a frequency of
     * 1 so far.
     */
    int sum = 1;
    char previous = s[0];
    for (int i = 1; i < s_count; ++i) {
        if (previous != s[i]) {
            /**
             * result += (previous + sum) 
             * sum = 0
             */
            strncat(result, &previous, 1);
            intToString(sum, result);

            sum = 0;
        }

        ++sum;
        previous = s[i];
    }

    char c = '\0';
    strncat(result, &c, 1);

    int length = strlen(result);

    if (length < s_count) {
        return result;
    } else {
        return s;
    }
}


/**
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example the string aabcccccaaa would become
 * a2b1c5a3. If the "compressed" string would not become smaller than the original,
 * your method should return the original string. You can assume the string has only
 * uppercase and lowercase letters (a-z).
 */
int main() {
    char s[] = "doodddd";
    int s_count = sizeof(s) / sizeof(char);
    char* result = (char*) malloc(s_count);
    printf("%s\n", stringCompression(s, s_count, result));
    free(result);
}