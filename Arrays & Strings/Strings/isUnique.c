#include "../Arrays/Sorting/quickSort.h"
#include <stdio.h>
#include <string.h>

/**
 * O(n)
 */
void charToIntArray(char* s, int s_count, int* arr) {
    for (int i = 0; i < s_count; ++i) {
        arr[i] = s[i];
    }
}

/**
 * O(n)
 * For the length of the string iterate until the implicit nul terminator is reached
 */
int getSize(char* s) {
    char* t;
    for (t = s; *t != '\0'; ++t);
    return t - s;
}

/**
 * O(n * log(n))
 * I use ++i instead of i++ because the former increments the pointer to the value, where the latter creates a new variable and reassigns
 * 
 * I could sort the array since characters are integers and then see if the current is equal to the previous
 */
int isUnqiue(char* s) {
    int s_count = getSize(s);
    int arr[s_count];

    charToIntArray(s, s_count, arr);
    quickSort(arr, 0, s_count - 1);

    for (int i = 1; i < s_count; ++i) {
        if (arr[i-1] == arr[i]) {
            return 0;
        }
    }

    return 1;
}

/**
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional data structures?
 */
int main() {
    char* s = "fghjklAAsd";
    printf("%d", isUnqiue(s));
}