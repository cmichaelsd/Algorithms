#include <stdio.h>

/**
 * O(c)
 */
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * O(i * n)
 * n = end - start
 * i = iterations
 */
void shiftLeft(char s[], int start, int end, int iterations) {
    while (iterations > 0) {
        for (int i = end; i > start; --i) {
            swap(&s[i-1], &s[i]);
        }   
        --iterations;
    }
}

/**
 * O(n)
 */
int count(char s[], int s_count, char value) {
    int count = 0;
    
    for (int i = 0; i < s_count; ++i) {
        if (s[i] == value) {
            ++count;
        }
    }

    return count;
}

/**
 * O(s * w(2 * n))
 * n = (Length of string * Number of spaces) - Location of white space
 * s = "Actual" length of string, Counting spaces
 * w = Number of whitespace
 */
void urlify(char s[], int s_count) {
    int spaces = count(s, s_count, ' ');
    int total = s_count + (spaces * 2) - 1;

    /**
     * Working back from string size
     */
    for (int i = s_count; i >= 0; --i) {
        /**
         * If I hit a space
         */
        if (s[i] == ' ') {
            /**
             * Set space to be %
             */
            s[i] = '%';

            /**
             * Set last two element to be 2, 0
             */
            s[total - 1] = '0';
            s[total - 2] = '2';

            /**
             * Exclusive from space
             * shiftLeft 2 iterations
             */
            shiftLeft(s, i + 1, total, 2);
        }
    }

    printf("%s", s);
}

int main() {
    char s[] = "Mr John Smith    ";
    int size = 13;
    urlify(s, size);
    return 0;
}