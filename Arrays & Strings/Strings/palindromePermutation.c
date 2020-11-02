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
         * Ignore control codes
         */
        if ((int) s[i] > 32) {

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

/**
 * O(n)
 * The input will never change the runtime for the frequency array its O(c)
 * 
 * n = Length of the string
 */
int palindromePermutation(char s[], int s_count) {
    int frequency[ASCII_CHAR_TOTAL];
    fill(frequency, ASCII_CHAR_TOTAL, 0);
    buildFrequencyArray(frequency, s, s_count);
    
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

    return 1;
}

/**
 * Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase
 * that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be
 * limited to just dictionary words.
 */
int main() {
    char s[] = "tacotaco";
    int s_count = sizeof(s) / sizeof(char);
    printf("%d\n", palindromePermutation(s, s_count));

    return 0;
}