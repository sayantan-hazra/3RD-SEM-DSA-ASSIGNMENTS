/*
4. Write a program in C to implement Insertion Sort with the following features:
   i) Insertion  ii) Sorting in ascending and descending order iii) Printing
*/

#include <stdio.h>
#include <stdlib.h>

void insertionSortAscending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDescending(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
        printf("\nInsertion Sort Operations:\n");
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
                insertionSortAscending(arr, n);
                printf("Array sorted in ascending order.\n");
                break;
            case 3:
                insertionSortDescending(arr, n);
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