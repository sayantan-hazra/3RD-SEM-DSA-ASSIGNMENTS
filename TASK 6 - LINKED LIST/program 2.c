/*
2. Represent a sparse matrix using a SLL.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row, col, value;
    struct Node *next;
};

struct Node *createSparseMatrix(int matrix[][100], int rows, int cols) {
    struct Node *head = NULL;
    struct Node *last = NULL;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->row = i;
                newNode->col = j;
                newNode->value = matrix[i][j];
                newNode->next = NULL;

                if (head == NULL) {
                    head = newNode;
                    last = newNode;
                } else {
                    last->next = newNode;
                    last = newNode;
                }
            }
        }
    }
    return head;
}

void displaySparseMatrix(struct Node *head) {
    printf("Row\tColumn\tValue\n");
    while (head != NULL) {
        printf("%d\t%d\t%d\n", head->row, head->col, head->value);
        head = head->next;
    }
}

int main() {
    int matrix[100][100] = {
        {0, 0, 3, 0},
        {0, 0, 5, 0},
        {0, 0, 0, 0},
        {0, 2, 0, 0}
    };
    int rows = 4, cols = 4;

    struct Node *sparseMatrix = createSparseMatrix(matrix, rows, cols);
    displaySparseMatrix(sparseMatrix);
    return 0;
}