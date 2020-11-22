#include <stdio.h>
#include "helpers.h"

/**
 * Time: O(n)
 * Space: O(c)
 * n = Length of string
 */
void urlify(char s[], int s_count) {
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
 * Array      size  total   i
 * cat_tom__  7     9       6
 * cat_tom_m  7     8       5
 * cat_tomom  7     7       4
 * cat%20tom  7     6       3
 * cat%20tom  7     3       2 => From here on out [total-1] == i, characters overwrite themselves
 * cat%20tom  7     2       1
 * cat%20tom  7     1       0
 */
int main() {
    char s[] = "Mr John Smith    ";
    int size = 13;
    urlify(s, size);
    printf("%s\n", s);
    return 0;
}