#ifndef STRING_HELPERS
#define STRING_HELPERS
#include <stdio.h>
#include <math.h>

const int ASCII_CHAR = 128;
const int ASCII_CHAR_EXTENDED =  ASCII_CHAR + ASCII_CHAR;

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
int int_count(int arr[], int arr_count, int value) {
    int count = 0;
    
    for (int i = 0; i < arr_count; ++i) {
        if (arr[i] == value) {
            ++count;
        }
    }

    return count;
}
/**
 * O(n)
 */
int char_count(char s[], int s_count, char value) {
    int count = 0;
    
    for (int i = 0; i < s_count; ++i) {
        if (s[i] == value) {
            ++count;
        }
    }

    return count;
}

/**
 * O(1)
 */
int getDecimal(int value, int tensPower) {
    return value % (int) pow(10, tensPower);
}

/**
 * O(1)
 */
int removeDecimal(int value, int tensPower) {
    int power = (int) pow(10, tensPower);
    int difference = value - (value % power);
    return difference / power;
}

/**
 * Time: O(n)
 * Space: O(c)
 * n = Number of digits long a value is
 */
int getDecimalsPlaceToLeft(int value) {
    int decimalsPlace = 0;

    while (value != 0) {
        value = value - getDecimal(value, ++decimalsPlace);
    }

    return decimalsPlace;
}

/**
 * Time: O(n)
 * Space: O(n)
 * n = Number of digits long a value is
 * 
 * Returns number of characters added to the string.
 */
int intToString(int value, char* s) {
    int decimalsToLeft = getDecimalsPlaceToLeft(value);
    char arr[decimalsToLeft];

    for (int i = decimalsToLeft - 1; i >= 0; --i) {
        arr[i] = getDecimal(value, 1) + '0';
        value = removeDecimal(value, 1);
    }

    strncat(s, arr, decimalsToLeft);

    return sizeof(arr) / sizeof(char);
}

/**
 * Time: O(n)
 * Space: O(c)
 */
int indexOf(char s[], size_t s_count, char c) {
    for (int i = 0; i < s_count; ++i) {
        if (s[i] == c) {
            return i;
        }
    }

    return -1;
}

/**
 * Time: O(n)
 * Space: O(c)
 */
int isSubstring(char source[], char substring[], size_t source_count, size_t substring_count) {
    if (source_count < substring_count) {
        return -1;
    }

    int index = 0;
    for (int i = 0; i < source_count; ++i) {
        if (index == substring_count - 1) {
            return i - index;
        }else if (source[i] == substring[index] && index < substring_count) {
            ++index;
        } else {
            index = 0;
        }
    }

    return -1;
}


#endif