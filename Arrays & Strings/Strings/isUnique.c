#include <stdio.h>
#include <string.h>

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
 * O()
 * I use ++i instead of i++ because the former increments the pointer to the value, where the latter creates a new variable and reassigns
 * 
 * I could sort the array since characters are integers and then see if the current is equal to the previous
 */
int isUnqiue(char* s, int s_count) {
    for (int i = 0; i < s_count; ++i) {

    }
}

/**
 * Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional data structures?
 */
int main() {
    char* s = "Asdfghjkl";
    int s_count = getSize(s);
    printf("%d", isUnqiue(s, s_count));
}