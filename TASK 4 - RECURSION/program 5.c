/*
5. Perform addition and subtraction of two 2x2 matrices using recursion.
*/

#include <stdio.h>

void addMatrices(int A[2][2], int B[2][2], int C[2][2], int i, int j) {
    if (i >= 2) return;
    if (j >= 2) {
        addMatrices(A, B, C, i + 1, 0);
        return;
    }
    C[i][j] = A[i][j] + B[i][j];
    addMatrices(A, B, C, i, j + 1);
}

void subtractMatrices(int A[2][2], int B[2][2], int C[2][2], int i, int j) {
    if (i >= 2) return;
    if (j >= 2) {
        subtractMatrices(A, B, C, i + 1, 0);
        return;
    }
    C[i][j] = A[i][j] - B[i][j];
    subtractMatrices(A, B, C, i, j + 1);
}

void displayMatrix(int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[2][2], B[2][2], C[2][2], D[2][2];

    printf("Enter elements of matrix A (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    addMatrices(A, B, C, 0, 0);
    printf("Sum of matrices:\n");
    displayMatrix(C);

    subtractMatrices(A, B, D, 0, 0);
    printf("Difference of matrices:\n");
    displayMatrix(D);

    return 0;
}