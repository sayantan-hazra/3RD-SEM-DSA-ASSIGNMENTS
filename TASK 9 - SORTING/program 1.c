/*
1. Implement Naive and Modified Bubble Sort.
*/

#include <stdio.h>

// Naive Bubble Sort
void naiveBubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Modified Bubble Sort (with early termination)
void modifiedBubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        // If no swaps occurred, array is sorted
        if (swapped == 0) break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    
    printf("Original array: ");
    printArray(arr1, n);
    
    naiveBubbleSort(arr1, n);
    printf("Naive Bubble Sorted array: ");
    printArray(arr1, n);
    
    modifiedBubbleSort(arr2, n);
    printf("Modified Bubble Sorted array: ");
    printArray(arr2, n);
    
    return 0;
}