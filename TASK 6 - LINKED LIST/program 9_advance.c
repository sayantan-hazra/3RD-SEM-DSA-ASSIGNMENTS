/*
9. Write a 'sort' function for sorting a SLL.
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

void sortList(struct Node *head) {
    struct Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[] = {4, 2, 1, 3};
    struct Node *list = createList(arr, 4);
    printf("Original List: ");
    display(list);

    sortList(list);
    printf("Sorted List: ");
    display(list);
    return 0;
}