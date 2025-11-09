/*
9. Implement Bucket Sort.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n) {
    // 1) Create n empty buckets
    float buckets[n][n];
    int bucketSize[n];
    for (int i = 0; i < n; i++)
        bucketSize[i] = 0;
    
    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        buckets[bi][bucketSize[bi]++] = arr[i];
    }
    
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++) {
        // Using insertion sort for simplicity
        for (int j = 1; j < bucketSize[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }
    
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < bucketSize[i]; j++)
            arr[index++] = buckets[i][j];
}

void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    bucketSort(arr, n);
    printf("Bucket Sorted array: ");
    printArray(arr, n);
    
    return 0;
}