/*
10. Implement Queue using two stacks.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int item) {
    if (top1 == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack1[++top1] = item;
}

int pop1() {
    if (top1 == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack1[top1--];
}

void push2(int item) {
    if (top2 == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack2[++top2] = item;
}

int pop2() {
    if (top2 == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack2[top2--];
}

void enqueue(int item) {
    push1(item);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    
    return pop2();
}

void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    
    // Print stack2 elements (front of queue)
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);
    
    // Print stack1 elements (rear of queue)
    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);
    
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued element: %d\n", dequeue());
    display();
    return 0;
}