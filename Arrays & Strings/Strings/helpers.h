#ifndef STRING_HELPERS
#define STRING_HELPERS
#include <stdio.h>
#include <math.h>

const int ASCII_CHAR = 128;
const int ASCII_CHAR_EXTENDED =  ASCII_CHAR + ASCII_CHAR;

/**
 * Time: O(n) 
 * Space: O(c) 
 * Fills every index of an integer array with the value parameter. 
 * 
 * @param int[] arr 
 * @param size_t arr_count 
 * @param int value 
 */
void fill(int arr[], size_t arr_count, int value) {
    for (int i = 0; i < arr_count; ++i) {
        arr[i] = value;
    }
}

/**
 * Time: O(n) 
 * Space: O(c) 
 * Returns 1 if every index in an integer array is equal to the value parameter otherwise 
 * 0 is returned. 
 * 
 * @param int[] arr 
 * @param size_t arr_count 
 * @param int value 
 * @return int 
 */
int every(int arr[], size_t arr_count, int value) {
    for (int i = 0; i < arr_count; ++i) {
        if (arr[i] != value) {
            return 0;
        }
    }

    return 1;
}

/**
 * Time: O(n) 
 * Space: O(c) 
 * Returns the number of times the value paramter is found within an integer 
 * array. 
 * 
 * @param int[] arr 
 * @param size_t arr_count 
 * @param int value 
 * @return int 
 */
int int_count(int arr[], size_t arr_count, int value) {
    int count = 0;
    
    for (int i = 0; i < arr_count; ++i) {
        if (arr[i] == value) {
            ++count;
        }
    }

    return count;
}
/**
 * Time: O(n) 
 * Space: O(c) 
 * Returns the number of times the value paramter is found within a character 
 * array. 
 * 
 * @param char[] s 
 * @param size_t s_count 
 * @param char value 
 * @return int 
 */
int char_count(char s[], size_t s_count, char value) {
    int count = 0;
    
    for (int i = 0; i < s_count; ++i) {
        if (s[i] == value) {
            ++count;
        }
    }

    return count;
}

/**
 * Time: O(log tensPower) 
 * Space: O(c) 
 * Returns the value at the decimal place associated with the tensPower parameter. 
 * 
 * @param int value 
 * @param int tensPower 
 * @return int 
 */
int getDecimal(int value, int tensPower) {
    return value % (int) pow(10, tensPower);
}

/**
 * Time: O(log tensPower) 
 * Space: O(c) 
 * Returns the value parameter with the decimal place associated with the tensPower parameter removed from the 
 * value. 
 *
 * @param int value 
 * @param int tensPower 
 * @return int 
 */
int removeDecimal(int value, int tensPower) {
    int power = (int) pow(10, tensPower);
    int difference = value - (value % power);
    return difference / power;
}

/**
 * Time: O(n) 
 * Space: O(c) 
 * n = Number of digits long a value is. 
 * Returns the number of decimal places to the left of 1's place. 
 * 
 * @param int value 
 * @return int 
 */
int getDecimalsPlaceToLeft(int value) {
    int decimalsPlace = 0;

    while (value != 0) {
        value = value - getDecimal(value, ++decimalsPlace);
    }

    return decimalsPlace;
}

/**
 * Time: O(n * log n) 
 * Space: O(n) 
 * n = Number of digits long a value is 
 * Appends as a characters the decimal places of value parameter 
 * to the character pointer. 
 * 
 * @param int value 
 * @param char* s 
 * @return int returns the number of characters added to the s parameter. 
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
 * Returns the index of at which the c parameter is found within a character array. 
 * 
 * @param char[] s 
 * @param size_t s_count 
 * @param char c 
 * @return int returns the index which c parameter is found otherwise -1 is returned. 
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
 * Returns index at which a substring is found in a string. 
 * 
 * @param char[] source 
 * @param char[] substring 
 * @param size_t source_count 
 * @param size_t substring_count 
 * @return int returns index of substring otherwise -1 is not found. 
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