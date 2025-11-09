/*
8. Implement Double-ended Queue using Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insertFront(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->prev = NULL;
    
    if (front == NULL) {
        newNode->next = NULL;
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

void insertRear(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;
    
    if (rear == NULL) {
        newNode->prev = NULL;
        front = rear = newNode;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
}

int deleteFront() {
    if (front == NULL) {
        printf("Deque Underflow\n");
        return -1;
    }
    struct Node* temp = front;
    int item = temp->data;
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
    return item;
}

int deleteRear() {
    if (rear == NULL) {
        printf("Deque Underflow\n");
        return -1;
    }
    struct Node* temp = rear;
    int item = temp->data;
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
    return item;
}

void display() {
    if (front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertFront(20);
    insertRear(30);
    display();
    printf("Deleted from front: %d\n", deleteFront());
    printf("Deleted from rear: %d\n", deleteRear());
    display();
    return 0;
}