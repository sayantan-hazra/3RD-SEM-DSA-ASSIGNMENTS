/*
7. Perform binary search using recursion.
*/

#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) return mid;
    else if (arr[mid] > key) return binarySearch(arr, left, mid - 1, key);
    else return binarySearch(arr, mid + 1, right, key);
}

int main() {
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        printf("Key not found.\n");
    } else {
        printf("Key found at index %d.\n", result);
    }
    return 0;
}