/*
1. Determine whether a matrix is Sparse or not, also represent it using 1D array.
*/

#include <stdio.h>

#define ROWS 3
#define COLS 3

void checkSparse(int matrix[ROWS][COLS]) {
    int zeroCount = 0;
    int totalElements = ROWS * COLS;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    if (zeroCount > totalElements / 2) {
        printf("The matrix is sparse.\n");
    } else {
        printf("The matrix is not sparse.\n");
    }
}

void represent1D(int matrix[ROWS][COLS]) {
    int sparseRep[100]; // Assuming max 100 non-zero elements
    int k = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != 0) {
                sparseRep[k++] = matrix[i][j];
            }
        }
    }

    printf("1D representation of non-zero elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", sparseRep[i]);
    }
    printf("\n");
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 0, 0},
        {0, 0, 2},
        {0, 3, 0}
    };

    checkSparse(matrix);
    represent1D(matrix);

    return 0;
}