/*
7. Find the sum and product of all the data elements in a SLL.
*/

#include <stdio.h>
#include <stdlib.h>

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

void sumAndProduct(struct Node *head) {
    int sum = 0, product = 1;
    while (head != NULL) {
        sum += head->data;
        product *= head->data;
        head = head->next;
    }
    printf("Sum: %d\nProduct: %d\n", sum, product);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    struct Node *list = createList(arr, 4);
    sumAndProduct(list);
    return 0;
}