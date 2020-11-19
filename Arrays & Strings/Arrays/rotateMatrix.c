#include <stdio.h>

void printIntMatrix(int matrix[5][5], int n_count) {
    for (int i = 0; i < n_count; ++i) {
        for (int j = 0; j < n_count; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Given an image represented by an NxN matrix, where each pixel in the image
 * is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this
 * in place?
 */
int main() {
    int n_count = 5;
    int matrix[][5] = {
        {1,1,0,1,0},
        {1,0,1,1,0},
        {0,1,1,0,1},
        {1,1,0,1,0},
        {0,1,0,1,0}
    };

    // rotateMatrix(matrix, n_count);
    printIntMatrix(matrix, n_count);

    return 0;
}