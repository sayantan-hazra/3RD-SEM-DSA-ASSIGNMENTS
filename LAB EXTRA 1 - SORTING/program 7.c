/*
7. Write a program in C to implement Merge Sort with the following features:
   i) Insertion  ii) Sorting in ascending and descending order iii) Printing
*/

#include <stdio.h>
#include <stdlib.h>

void mergeAscending(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeDescending(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortAscending(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortAscending(arr, l, m);
        mergeSortAscending(arr, m + 1, r);
        mergeAscending(arr, l, m, r);
    }
}

void mergeSortDescending(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortDescending(arr, l, m);
        mergeSortDescending(arr, m + 1, r);
        mergeDescending(arr, l, m, r);
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
        printf("\nMerge Sort Operations:\n");
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
                mergeSortAscending(arr, 0, n-1);
                printf("Array sorted in ascending order.\n");
                break;
            case 3:
                mergeSortDescending(arr, 0, n-1);
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
