/*
4. Concatenate two SLLs.
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

struct Node *concatenate(struct Node *list1, struct Node *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node *temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    struct Node *list1 = createList(arr1, 3);
    struct Node *list2 = createList(arr2, 3);

    struct Node *result = concatenate(list1, list2);
    display(result);
    return 0;
}