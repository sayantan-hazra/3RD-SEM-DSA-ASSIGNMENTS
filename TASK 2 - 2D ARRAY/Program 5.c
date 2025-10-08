/*Program 5: Diagonal elements of a matrix */

#include <stdio.h>

int main() {
    int a[10][10];
    int i, j, n;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Main diagonal: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i][i]);

    printf("\nSecondary diagonal: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i][n - i - 1]);

    return 0;
}
