#ifndef ARRAY_HELPERS
#define ARRAY_HELPERS
#include <stdio.h>

const int MATRIX_SIZE = 4;

void printIntMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], int n_count) {
    for (int i = 0; i < n_count; ++i) {
        for (int j = 0; j < n_count; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

#endif