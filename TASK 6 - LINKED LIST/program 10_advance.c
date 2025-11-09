/*
10. Check whether a SLL is palindrome or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isPalindrome(struct Node *head) {
    int arr[100], i = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    int left = 0, right = i - 1;
    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int arr1[] = {1, 2, 2, 1};
    struct Node *list1 = createList(arr1, 4);
    printf("List 1 is %s\n", isPalindrome(list1) ? "palindrome" : "not palindrome");

    int arr2[] = {1, 2, 3, 4};
    struct Node *list2 = createList(arr2, 4);
    printf("List 2 is %s\n", isPalindrome(list2) ? "palindrome" : "not palindrome");
    return 0;
}