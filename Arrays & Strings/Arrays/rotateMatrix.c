#include <stdio.h>
#include "helpers.h"

/**
 * Time: O(n^2) 
 * Space: O(n) 
 * n = Number of elements.
 * Rotates entire NxN matrix 90 degrees. 
 * 
 * @param int[][] matrix 
 * @param size_t n_count
 */
void rotateMatrix(int matrix[MATRIX_N][MATRIX_N], size_t n_count) {
    for (int layer = 0; layer < (n_count / 2); ++layer) {
        int start = layer;
        int end = n_count - 1 - start;
        for (int i = start; i < end; ++i) {
            int offset = i - start;
            
            /* Save top left */
            int temp = matrix[start][i];

            // /* Assign bottom left to top left */
            matrix[start][i] = matrix[end-offset][start];

            // /* Assign bottom right to bottom left */
            matrix[end-offset][start] = matrix[end][end-offset];

            // /* Assign top right to bottom left */
            matrix[end][end-offset] = matrix[i][end];

            // /* Assign top right to temp */
            matrix[i][end] = temp;
        }
    }
}

/**
 * Given an image represented by an NxN matrix, where each pixel in the image
 * is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this
 * in place?
 */
int main() {
    int matrix[MATRIX_N][MATRIX_N] = {
        {1,2,3,4},
        {2,8,9,5},
        {1,6,0,6},
        {0,9,8,7}
    };

    printIntNxNMatrix(matrix, MATRIX_N);
    printf("\n\n");
    printIntNxNMatrix(matrix, MATRIX_N);
    printIntNxNMatrix(matrix, MATRIX_N);

    return 0;
}