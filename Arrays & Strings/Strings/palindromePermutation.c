#include <stdio.h>

/**
 * O(c)
 * 
 * This function is to find if our series of bits only contain a single one.
 * Theres a trick for this lets say I have 8
 * 0000 1000 -> 8 (2^3)
 * 0000 0111 -> 7 (2^2 + 2^1 + 2^0) or (4 + 2 + 1) subtract our current bit vector by 1
 * 
 * The values of the binary numbers aren't important, just pretend its an array of ones and zeros (which could be seen as a number if you really wanted to)
 * 
 *   0000 1000
 *  &0000 0111
 *  ----------
 *   0000 0000  Pass case
 * 
 *   0000 1001 (9)
 *  &0000 1000 (8)
 *  ----------
 *   0000 1000 Fail case
 */
int checkExactlyOneBitSet(int bitVector) {
    return (bitVector & (bitVector - 1)) == 0;
}

/**
 * O(c)
 * This may seem confusing but with a little study it becomes very clear. If you are confused read the first few chapters of 
 * Code: The Hidden Language of Computer Hardware and Software by Charles Petzold
 * This problem if based on a concept in electrical engineering - logic gates - and therefore computer programing.
 * 
 * For a fake example I will pretend the character code for 'a' is 3, the bit vector will then look like this 0000 1000
 * 
 * Least significant digit (right) to most significant digit (left) can be thought of as an array which is zero indexed
 * this is why the fourth from the left is now a one.
 */
int toggle(int bitVector, int index) {
    if (index < 0) return bitVector;

    /**
     * This mask is what is sending a one down the series until it is at the index which is the character code
     */
    int mask = 1 << index;

    /**
     * If the current bit vector does not have a character already at this index
     * 1 AND 0 = 0
     * 1 AND 1 = 1
     */
    if ((bitVector & mask) == 0) {
        /**
         * Add the bit to the bit vector
         * 1 | 0 = 1
         */
        bitVector |= mask;
    } else {
        /**
         * Otherwise if a bit already exists in this position
         * Toggle it off
         * 
         * We care about pairs of numbers. If I enter an (fake example) 'a' we have 0000 1000 if I enter another 'a' we
         * have a bit already at position 3.
         * 
         * We then set the inverse of the mask to the bit vector
         * 0000 1000 -> bit vector
         * 1111 0111 -> inverted mask
         * 0000 0000 -> result
         * this removes the current bit from our bit vector
         */
        bitVector &= ~mask;
    }

    return bitVector;
}

/**
 * O(n)
 * n = length of the string
 * 
 * This will create a bit vector which is just a way of saying a series of ones and zeros
 * The idea is to send a 1 to the index in this number which is the character code
 */
int createBitVector(char s[], int s_count) {
    int bitVector = 0;

    for (int i = 0; i < s_count; ++i) {
        bitVector = toggle(bitVector, s[i]);
    }

    return bitVector;
}

/**
 * O(n)
 * I wanted to write out the bit vector solution to deeply understand why it is working
 */
int palindromePermutation(char s[], int s_count) {
    int bitVector = createBitVector(s, s_count);
    return bitVector == 0 || checkExactlyOneBitSet(bitVector);
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











// BELOW: I wanted to save this frequency implementation

// const int ASCII_CHAR_TOTAL = 256;

// /**
//  * O(c)
//  * I could just say isEven(n) == 0
//  * but I'm trying to be more readable
//  */
// int isOdd(int n) {
//     return n % 2 == 1;
// }

// /**
//  * O(n)
//  */
// int count(int arr[], int arr_count, int (*ptr)()) {
//     int total = 0;

//     for (int i = 0; i < arr_count; ++i) {
//         if ((*ptr)(arr[i]) == 1) {
//             ++total;
//         }
//     }

//     return total;
// }

// /**
//  * O(n)
//  */
// void fill(int arr[], int arr_count, int value) {
//     for (int i = 0; i < arr_count; ++i) {
//         arr[i] = value;
//     }
// }

// /**
//  * O(n)
//  */
// void buildFrequencyArray(int dest[], char s[], int s_count) {
//     for (int i = 0; i < s_count; ++i) {

//         /**
//          * Ignore control codes
//          */
//         if ((int) s[i] > 32) {

//             /**
//              * Ignore capitalization
//              * Make capitals lowercase
//              */
//             if (65 <= (int) s[i] && (int) s[i] <= 90) {
//                 s[i] = s[i] + 32;
//             }

//             ++dest[s[i]];
//         }
//     }
// }

// /**
//  * O(n)
//  * The input will never change the runtime for the frequency array its O(c)
//  * 
//  * n = Length of the string
//  */
// int palindromePermutation(char s[], int s_count) {
//     int frequency[ASCII_CHAR_TOTAL];
//     fill(frequency, ASCII_CHAR_TOTAL, 0);
//     buildFrequencyArray(frequency, s, s_count);
    
//     int oddFrequencies = count(frequency, ASCII_CHAR_TOTAL, &isOdd);
    
//     /**
//      * You cannot have an odd lengthed string which has multiple
//      * odd frequencies and is also a palindrome
//      * 
//      * efefefe (one odd frequency) -> true
//      * efefefb (two odd frequencies) -> false
//      * tacocat (one odd frequency) -> true
//      * abcdefg (seven odd frequencies) -> false
//      */
//     if (oddFrequencies > 1) {
//         return 0;
//     }

//     return 1;
// }