#include <stdio.h>
#include <string.h>

/**
 * Time: O(n)
 * Space: O(n)
 */
int isUnqiue(char* s) {
    int bitVector = 0;

    for (int i = 0; i < strlen(s); ++i) {
        int mask = 1 << s[i];
        if ((bitVector & mask) != 0) {
            return 0;
        }
        bitVector |= mask;
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
    return 0;
}



// BELOW: Frequency implementation

// #include "helpers.h"

// /**
//  * Method 1)
//  * O(n * log(n)) using Quick Sort
//  * I could sort the array since characters are integers and then see if the current is equal to the previous
//  * 
//  * Method 2)
//  * O(n) or O(c) because the input will never change the worst case being 256 iteration
//  * Use the information from the ASCII website and use the array as a record of previously seen values
//  * 
//  * I use ++i instead of i++ because the former increments the pointer to the value, where the latter creates a new variable and reassigns
//  */
// int isUnqiue(char* s) {
//     /* On the ASCII website they claim the range is from 0-127 for character codes, 255 for extended charcter codes */
//     int arr[ASCI_CHAR_EXTENDED];
//     fill(arr, ASCI_CHAR_EXTENDED, 0);

//     for (int i = 0; i < strlen(s); ++i) {
//         int charIndex = s[i];
//         if (arr[charIndex] == 0) {
//             arr[charIndex] = 1;
//         } else {
//             return 0;
//         }
//     }

//     return 1;
// }