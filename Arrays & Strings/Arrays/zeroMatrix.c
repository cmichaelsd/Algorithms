#include <stdio.h>
#include "helpers.h"

/**
 * O(n)
 */
void removeRow(int matrix[MATRIX_M][MATRIX_N], int row, int n_count) {
    for (int i = 0; i < n_count; ++i) {
        matrix[row][i] = 0;
    }
}

/**
 * O(m)
 */
void removeColumn(int matrix[MATRIX_M][MATRIX_N], int column, int m_count) {
    for (int i = 0; i < m_count; ++i) {
        matrix[i][column] = 0;
    }
}

/**
 * Time: O(m * n)
 * Space: O(1)
 * 
 * I previously used a bit vector solution but it was O(n) space.
 */
void zeroMatrix(int matrix[MATRIX_M][MATRIX_N], int m_count, int n_count) {
    int rowHasZero= 0;
    int columnHasZero = 0;

    /**
     * See if first row has a zero.
     */
    for (int column = 0; column < n_count; ++column) {
        if (matrix[0][column] == 0) {
            rowHasZero = 1;
            break;
        }
    }

    /**
     * See if first column has a zero.
     */
    for (int row = 0; row < m_count; ++row) {
        if (matrix[row][0] == 0) {
            columnHasZero = 1;
            break;
        }
    }

    /**
     * If a zero is found in the rest of the matrix.
     * At the found index set the first row at index to zero
     * At the found index set the first column at index to zero
     */
    for (int row = 1; row < m_count; ++row) {
        for (int column = 1; column < m_count; ++column) {
            if (matrix[row][column] == 0) {
                matrix[row][0] = 0;
                matrix[0][column] = 0;
            }
        }
    }

    /**
     * If any column but the first has a zero set column to zero.
     */
    for (int column = 1; column < n_count; ++column) {
        if (matrix[0][column] == 0) {
            removeColumn(matrix, column, m_count);
        }
    }

    /**
     * If any row but the first has a zero set row to zero.
     */
    for (int row = 1; row < m_count; ++row) {
        if (matrix[row][0] == 0) {
            removeRow(matrix, row, n_count);
        }
    }

    /**
     * If the first row originally had a zero set first row to zero.
     */
    if (rowHasZero) {
        removeRow(matrix, 0, n_count);
    }

    /**
     * If the first column originally had a zero set first column to zero.
     */
    if (columnHasZero) {
        removeColumn(matrix, 0, m_count);
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

    printIntMxNMatrix(matrix, MATRIX_M, MATRIX_N);
    printf("\n\n");
    zeroMatrix(matrix, MATRIX_M, MATRIX_N);
    printIntMxNMatrix(matrix, MATRIX_M, MATRIX_N);
}