/*
9. Implement Stack using two queues.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue1[MAX], queue2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue1(int item) {
    if (rear1 == MAX-1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front1 == -1)
        front1 = 0;
    queue1[++rear1] = item;
}

int dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue1[front1++];
}

void enqueue2(int item) {
    if (rear2 == MAX-1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front2 == -1)
        front2 = 0;
    queue2[++rear2] = item;
}

int dequeue2() {
    if (front2 == -1 || front2 > rear2) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue2[front2++];
}

void push(int item) {
    enqueue1(item);
}

int pop() {
    if (front1 == -1 && front2 == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    // Move all elements from queue1 to queue2 except last one
    while (front1 != rear1) {
        enqueue2(dequeue1());
    }
    
    // Dequeue the last element from queue1
    int item = dequeue1();
    
    // Swap the names of queue1 and queue2
    int tempFront = front1;
    int tempRear = rear1;
    front1 = front2;
    rear1 = rear2;
    front2 = tempFront;
    rear2 = tempRear;
    
    return item;
}

void display() {
    if (front1 == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", queue1[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped element: %d\n", pop());
    display();
    return 0;
}