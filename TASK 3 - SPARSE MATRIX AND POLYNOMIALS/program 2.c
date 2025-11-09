/*
2. Add and Multiply two sparse matrices and check whether their sum and product are also Sparse or not.
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

void addMatrices(int A[ROWS][COLS], int B[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[ROWS][COLS], int B[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[ROWS][COLS] = {
        {1, 0, 0},
        {0, 0, 2},
        {0, 3, 0}
    };

    int B[ROWS][COLS] = {
        {0, 0, 3},
        {0, 4, 0},
        {5, 0, 0}
    };

    int sum[ROWS][COLS], product[ROWS][COLS];

    addMatrices(A, B, sum);
    multiplyMatrices(A, B, product);

    printf("Sum of matrices:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    printf("Is sum sparse? ");
    checkSparse(sum);

    printf("\nProduct of matrices:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
    printf("Is product sparse? ");
    checkSparse(product);

    return 0;
}