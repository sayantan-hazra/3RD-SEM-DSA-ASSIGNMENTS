/*
5. Implement Priority Queue using array.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Item {
    int data;
    int priority;
};

struct Item queue[MAX];
int rear = -1;

void enqueue(int data, int priority) {
    if (rear == MAX-1) {
        printf("Queue Overflow\n");
        return;
    }
    rear++;
    queue[rear].data = data;
    queue[rear].priority = priority;
}

int peek() {
    int highestPriority = -1;
    int index = -1;
    
    for (int i = 0; i <= rear; i++) {
        if (queue[i].priority > highestPriority) {
            highestPriority = queue[i].priority;
            index = i;
        }
    }
    return index;
}

int dequeue() {
    if (rear == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    
    int index = peek();
    int item = queue[index].data;
    
    for (int i = index; i < rear; i++) {
        queue[i] = queue[i+1];
    }
    rear--;
    
    return item;
}

void display() {
    if (rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i <= rear; i++)
        printf("(%d, %d) ", queue[i].data, queue[i].priority);
    printf("\n");
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    display();
    printf("Dequeued element: %d\n", dequeue());
    display();
    return 0;
}