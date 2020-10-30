#include <stdio.h>

const int ASCII_CHAR_TOTAL = 128;

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
 * For the length of the string iterate until the implicit nul terminator is reached
 * I could do this in the main function but this is a useful helper function
 * and doing this inline makes things much more unreadable
 */
int getSize(char* s) {
    char* t;
    for (t = s; *t != '\0'; ++t);
    return t - s;
}

/**
 * Method 1)
 * O(n * log(n)) using Quick Sort
 * I could sort the array since characters are integers and then see if the current is equal to the previous
 * 
 * Method 2)
 * O(n) or O(c) because the input will never change the worst case being 128 iteration
 * Use the information from the ASCII website and use the array as a record of previously seen values
 * 
 * I use ++i instead of i++ because the former increments the pointer to the value, where the latter creates a new variable and reassigns
 */
int isUnqiue(char* s) {
    int s_count = getSize(s);
    /* On the ASCII website they claim the range is from 0-127 for character codes*/
    int arr[ASCII_CHAR_TOTAL];
    fill(arr, ASCII_CHAR_TOTAL, 0);

    for (int i = 0; i < s_count; ++i) {
        int charIndex = s[i];
        if (arr[charIndex] == 0) {
            arr[charIndex] = 1;
        } else {
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
    char* s = "abcdefghijklmnop";
    printf("%d", isUnqiue(s));
}