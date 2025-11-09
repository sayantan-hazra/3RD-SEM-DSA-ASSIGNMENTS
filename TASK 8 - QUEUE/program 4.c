/*
4. Implement Circular Queue using Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rear = NULL;

void enqueue(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    
    if (rear == NULL) {
        rear = newNode;
        rear->next = rear;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (rear == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    
    int item;
    if (rear->next == rear) {
        item = rear->data;
        free(rear);
        rear = NULL;
    } else {
        struct Node* temp = rear->next;
        item = temp->data;
        rear->next = temp->next;
        free(temp);
    }
    return item;
}

void display() {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    struct Node* temp = rear->next;
    printf("Queue elements: ");
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(15);
    enqueue(25);
    display();
    printf("Dequeued element: %d\n", dequeue());
    display();
    return 0;
}