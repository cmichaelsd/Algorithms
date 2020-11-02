#include <stdio.h>

const int ASCII_CHAR_TOTAL = 256;

/**
 * O(c)
 * I could just say isEven(n) == 0
 * but I'm trying to be more readable
 */
int isOdd(int n) {
    return n % 2 == 1;
}

/**
 * O(c)
 */
int isEven(int n) {
    return n % 2 == 0;
}

/**
 * O(n)
 */
int count(int arr[], int arr_count, int (*ptr)()) {
    int total = 0;

    for (int i = 0; i < arr_count; ++i) {
        if ((*ptr)(arr[i]) == 1) {
            ++total;
        }
    }

    return total;
}

/**
 * O(n)
 * Decided to update the every function to take a callback
 * I can now dynamically check conditions
 */
int every(int arr[], int arr_count, int (*ptr)()) {
    for (int i = 0; i < arr_count; ++i) {
        if ((*ptr)(arr[i]) == 0) {
            return 0;
        }
    }

    return 1;
}

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
void buildFrequencyArray(int dest[], char s[], int s_count) {
    for (int i = 0; i < s_count; ++i) {

        /**
         * Ignore control codes and spaces
         */
        if ((int) s[i] > 32 && (int) s[i] != 173) {

            /**
             * Ignore capitalization
             * Make capitals lowercase
             */
            if (65 <= (int) s[i] && (int) s[i] <= 90) {
                s[i] = s[i] + 32;
            }

            ++dest[s[i]];
        }
    }
}

int palindromePermutation(char s[], int s_count) {
    int frequency[ASCII_CHAR_TOTAL];
    int trueSize = 0;
    fill(frequency, ASCII_CHAR_TOTAL, 0);
    buildFrequencyArray(frequency, s, s_count);

    /**
     * Find true length of the string (no control or space characters)
     */
    for (int i = 0; i < s_count; ++i) {
        if ((int) s[i] >= 32 && (int) s[i] != 173) {
            ++trueSize;
        }
    }
    
    if (isOdd(trueSize - 1)) {
        int oddFrequencies = count(frequency, ASCII_CHAR_TOTAL, &isOdd);
        
        /**
         * You cannot have an odd lengthed string which has multiple
         * odd frequencies and is also a palindrome
         * 
         * efefefe (one odd frequency) -> true
         * efefefb (two odd frequencies) -> false
         * tacocat (one odd frequency) -> true
         * abcdefg (seven odd frequencies) -> false
         */
        if (oddFrequencies > 1) {
            return 0;
        }
    } else {
        int allElementsEven = every(frequency, ASCII_CHAR_TOTAL, &isEven);

        if (allElementsEven == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char s[] = "tacotaco";
    int s_count = sizeof(s) / sizeof(char);
    printf("%d\n", palindromePermutation(s, s_count));

    return 0;
}