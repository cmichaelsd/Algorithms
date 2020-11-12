#include <stdio.h>

char* stringCompression(char* s, int s_count) {
    /**
     * s = aabcccccaaa
     * expected = a2b1c5a3
     * 
     * result = ""
     * sum = 0;
     * 
     * for (int i = 0; i < s_count; ++i) {
     *   a != a, sum = 1
     *   a != b, sum = 2, result = a2, sum = 0
     *   b != c, sum = 1, result = a2b1, sum = 0
     *   c != c, sum = 1
     *   ...
     *   c != a, sum = 5, result = a2b1c5, sum = 0
     *   ...
     *   a != a, sum = 3, result = a2b1c5a3, sum = 0
     * 
     *   ++sum;
     *   if (s[i] != s[i+1]) { // protect i+1 from getting false results out of bounds
     *     result = s[i] + sum;
     *     sum = 0;
     *   }
     * }
     */
}


/**
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example the string aabcccccaaa would become
 * a2b1c5a3. If the "compressed" string would not become smaller than the original,
 * your method should return the original string. You can assume the string has only
 * uppercase and lowercase letters (a-z).
 */
int main() {
    char* s = "aabcccccaaa";
    int s_count = 11;
    printf("%s\n", stringCompression(s, s_count));
}