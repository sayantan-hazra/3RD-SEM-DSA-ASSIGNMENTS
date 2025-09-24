/*Program 1: Insert element at specific position in array*/


#include <stdio.h>

int main() {
    int arr[100], n, i, pos, val;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &val);
    
    if(pos < 0 || pos > n) {
        printf("Invalid position.\n");
        return 1;
    }
    
    for(i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    
    arr[pos] = val;
    n++;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

