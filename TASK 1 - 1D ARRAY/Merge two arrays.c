/*Program 5: Merge two arrays*/

#include <stdio.h>

int main() {
    int arr1[50], arr2[50], merged[100];
    int n1, n2, i;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);
    printf("Enter %d elements:\n", n1);
    for(i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);
    printf("Enter %d elements:\n", n2);
    for(i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    for(i = 0; i < n1; i++)
        merged[i] = arr1[i];

    for(i = 0; i < n2; i++)
        merged[n1 + i] = arr2[i];

    printf("Merged array:\n");
    for(i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);

    return 0;
}
