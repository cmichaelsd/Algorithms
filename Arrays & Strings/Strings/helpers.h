#ifndef STRING_HELPERS
#define STRING_HELPERS
#include <stdio.h>
#include <math.h>

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
 * O(n)
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
 * O(n)
 * n = Number of digits long a value is
 */
void intToString(int value, char* s) {
    int decimalsToLeft = getDecimalsPlaceToLeft(value);
    char arr[decimalsToLeft];

    for (int i = decimalsToLeft - 1; i >= 0; --i) {
        arr[i] = getDecimal(value, 1) + '0';
        value = removeDecimal(value, 1);
    }

    strncat(s, arr, decimalsToLeft);
}

int indexOf(char s[], int s_count, char c) {
    for (int i = 0; i < s_count; ++i) {
        if (s[i] == c) {
            return i;
        }
    }

    return -1;
}


#endif