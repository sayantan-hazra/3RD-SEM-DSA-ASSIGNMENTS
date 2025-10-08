/*Program 4: Transpose of a matrix */

#include <stdio.h>

int main() {
    int a[10][10], trans[10][10];
    int i, j, rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of the matrix:\n");
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            trans[j][i] = a[i][j];

    printf("Transpose of matrix:\n");
    for(i = 0; i < cols; i++) {
        for(j = 0; j < rows; j++)
            printf("%d ", trans[i][j]);
        printf("\n");
    }

    return 0;
}
