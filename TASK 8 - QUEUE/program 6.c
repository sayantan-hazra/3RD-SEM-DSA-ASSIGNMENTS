/*
6. Implement Double-ended Queue using array.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int item) {
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX-1;
    } else {
        front--;
    }
    deque[front] = item;
}

void insertRear(int item) {
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX-1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = item;
}

int deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return -1;
    }
    int item = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX-1) {
        front = 0;
    } else {
        front++;
    }
    return item;
}

int deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return -1;
    }
    int item = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX-1;
    } else {
        rear--;
    }
    return item;
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    if (front <= rear) {
        while (i <= rear)
            printf("%d ", deque[i++]);
    } else {
        while (i < MAX)
            printf("%d ", deque[i++]);
        i = 0;
        while (i <= rear)
            printf("%d ", deque[i++]);
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