#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

/**
 * O(n)
 * 
 * n = Length of input string
 * 
 * The same number of operations occur for each element in the input string.
 * 
 * Could have issues with the result string in a case where to compressed string is larger
 * than original string.
 * 
 * abcdefghi
 * a1b1c1d1e1f1g1h1i1
 * 
 * Worst case new string can be twice as large as original. This is handled by checking if 
 * the current length of the result is larger than input string.
 */
char* stringCompression(char s[], int s_count, char* result) {
    if (s_count < 4) {
        /**
         * The ideal case "aaa\0" could become "a2\0"
         * Need at least 4 characters to bother with the logic below
         */
        return s;
    }

    /**
     * Set first character as previous and set for loop to iterate
     * at 1. Set sum to 1 as previous character must have a frequency of
     * 1 so far.
     */
    int result_count = 0;
    int sum = 1;
    char previous = s[0];
    for (int i = 1; i < s_count; ++i) {
        if (result_count >= s_count) {
            break;
        }

        if (previous != s[i]) {
            /**
             * result += (previous + sum) 
             * sum = 0
             */
            strncat(result, &previous, 1);

            /**
             * Add number of characters to result_count plus the single character
             * currently being processed.
             */
            result_count += (intToString(sum, result) + 1);

            sum = 0;
        }

        ++sum;
        previous = s[i];
    }

    if (result_count < s_count) {
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
    char s[] = "aaacdefghi";
    int s_count = sizeof(s) / sizeof(char);
    char* result = (char*) malloc(s_count);
    printf("%s\n", stringCompression(s, s_count, result));
    free(result);

    return 0;
}