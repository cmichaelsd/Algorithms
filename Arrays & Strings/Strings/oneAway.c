#include <stdio.h>

const int ASCII_CHAR_TOTAL = 256;

void fill(int arr[], int arr_count, int value) {
    for (int i = 0; i < arr_count; ++i) {
        arr[i] = value;
    }
}

/**
 * O(a + b)
 * a = Length of string one
 * b = Length of string two
 */
int oneAway(char s1[], int s1_count, char s2[], int s2_count) {
    /**
     * int frequency[ascii]
     * 
     * for (i = 0; i < s1_count; ++i)
     *  ++frequency[s1[i]]
     * 
     * for (i = 0; i < s2_count; ++i)
     *  --frequency[s2[i]]
     * 
     * count = 0;
     * for (i = 0; i < ascii; ++i)
     *  if (frequency[i] != 0)
     *    ++count
     * 
     * return count == 1 || count == 0
     */
    int count = 0;
    int frequency[ASCII_CHAR_TOTAL];
    fill(frequency, ASCII_CHAR_TOTAL, 0);

    for (int i = 0; i < s1_count; ++i) {
        ++frequency[s1[i]];
    }

    for (int i = 0; i < s2_count; ++i) {
        --frequency[s2[i]];
    }

    for (int i = 0; i < s1_count; ++i) {
        if (frequency[s1[i]] != 0) {
            --frequency[s1[i]];
        }
    }

    for (int i = 0; i < ASCII_CHAR_TOTAL; ++i) {
        if (frequency[i] != 0) {
            ++count;
        }
    }

    printf("%d\n", count);

    // return count == 1 || count == 0;
    return 0;

}

/**
 * There are three types of edits that can be performed on strings: 
 * insert a characer, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit
 * (or zero edits) away.
 */
int main() {
    char s1[] = "aaa";
    char s2[] = "aa";
    int s1_count = sizeof(s1) / sizeof(char);
    int s2_count = sizeof(s2) / sizeof(char);
    printf("%d\n", oneAway(s1, s1_count, s2, s2_count));
    return 0;
}