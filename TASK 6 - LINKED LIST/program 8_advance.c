/*
8. Find maximum and minimum element of a SLL.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createList(int arr[], int n) {
    struct Node *head = NULL;
    struct Node *last = NULL;

    for (int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    return head;
}

void findMaxMin(struct Node *head) {
    int max = INT_MIN, min = INT_MAX;
    while (head != NULL) {
        if (head->data > max) max = head->data;
        if (head->data < min) min = head->data;
        head = head->next;
    }
    printf("Max: %d\nMin: %d\n", max, min);
}

int main() {
    int arr[] = {10, 5, 20, 15};
    struct Node *list = createList(arr, 4);
    findMaxMin(list);
    return 0;
}