/*
5. Write a program in C to implement Quick Sort with the following features:
   i) Insertion  ii) Sorting in ascending and descending order iii) Printing
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partitionAscending(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partitionDescending(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortAscending(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionAscending(arr, low, high);
        quickSortAscending(arr, low, pi - 1);
        quickSortAscending(arr, pi + 1, high);
    }
}

void quickSortDescending(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionDescending(arr, low, high);
        quickSortDescending(arr, low, pi - 1);
        quickSortDescending(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int *n, int capacity, int element) {
    if (*n >= capacity) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }
    arr[*n] = element;
    (*n)++;
}

int main() {
    int capacity = 100;
    int arr[capacity];
    int n = 0;
    int choice, element;
    
    while (1) {
        printf("\nQuick Sort Operations:\n");
        printf("1. Insert element\n");
        printf("2. Sort in ascending order\n");
        printf("3. Sort in descending order\n");
        printf("4. Print array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertElement(arr, &n, capacity, element);
                break;
            case 2:
                quickSortAscending(arr, 0, n-1);
                printf("Array sorted in ascending order.\n");
                break;
            case 3:
                quickSortDescending(arr, 0, n-1);
                printf("Array sorted in descending order.\n");
                break;
            case 4:
                printf("Current array: ");
                printArray(arr, n);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}