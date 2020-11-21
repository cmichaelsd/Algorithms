#include <stdio.h>
#include "helpers.h"

void zeroMatrix(int matrix[MATRIX_M][MATRIX_N], int m_count, int n_count) {
    int indiciesMatrix[m_count][n_count];
    matrixMxNFill(indiciesMatrix, m_count, n_count, 1);

    /* Map found zeros to indicies matrix */
    for (int row = 0; row < m_count; ++row) {
        for (int column = 0; column < n_count; ++column) {
            if (matrix[row][column] == 0) {
                indiciesMatrix[row][column] = 0;
            }
        }
    }

    /**
     * Search indicies for a found zero.
     * Based on that indcies row set all items of matching row in matrix to zero
     * Based on that indcies column set all items of matching column in matrix to zero
     */
    for (int row = 0; row < m_count; ++row) {
        for (int column = 0; column < n_count; ++column) {
            if (indiciesMatrix[row][column] == 0) {
                for (int i = 0; i < n_count; ++i) {
                    matrix[row][i] = 0;
                }
                for (int j = 0; j < m_count; ++j) {
                    matrix[j][column] = 0;
                }
            }
        }
    }
}

/**
 * Write an algorithm such that if an element in an MxN matrix is 0,
 * its entire row and column are set to 0.
 */
int main() {
    int matrix[MATRIX_M][MATRIX_N] = {
        {0,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,0},
    };

    printIntMxNMAtrix(matrix, MATRIX_M, MATRIX_N);
    printf("\n\n");
    zeroMatrix(matrix, MATRIX_M, MATRIX_N);
    printIntMxNMAtrix(matrix, MATRIX_M, MATRIX_N);
}