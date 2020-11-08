#ifndef STRING_HELPERS
#define STRING_HELPERS
#include <stdio.h>

const int ASCII_CHAR = 128;
const int ASCI_CHAR_EXTENDED =  ASCII_CHAR + ASCII_CHAR;

/**
 * O(n)
 */
void fill(int arr[], int arr_count, int value) {
    for (int i = 0; i < arr_count; ++i) {
        arr[i] = value;
    }
}

/**
 * O(n)
 */
int every(int arr[], int arr_count, int value) {
    for (int i = 0; i < arr_count; ++i) {
        if (arr[i] != value) {
            return 0;
        }
    }

    return 1;
}

/**
 * O(n)
 * 
 * Update to be an integer array and learn how to cast the string array 
 * to an integer array
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



#endif