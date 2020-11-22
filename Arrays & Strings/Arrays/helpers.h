#ifndef ARRAY_HELPERS
#define ARRAY_HELPERS
#include <stdio.h>

const size_t MATRIX_M = 6;
const size_t MATRIX_N = 4;

void matrixMxNFill(int matrix[MATRIX_M][MATRIX_N], size_t m_count, size_t n_count, int value) {
    for (int i = 0; i < m_count; ++i) {
        for (int j = 0; j < n_count; ++j) {
            matrix[i][j] = value;
        }
    }
}

void printIntMxNMatrix(int matrix[MATRIX_M][MATRIX_N], size_t m_count, size_t n_count) {
    for (int i = 0; i < m_count; ++i) {
        for (int j = 0; j < n_count; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printIntNxNMatrix(int matrix[MATRIX_N][MATRIX_N], size_t n_count) {
    for (int i = 0; i < n_count; ++i) {
        for (int j = 0; j < n_count; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

#endif