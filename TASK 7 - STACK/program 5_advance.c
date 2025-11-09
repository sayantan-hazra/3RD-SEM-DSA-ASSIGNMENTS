/*
5. Implement Stack using Single Circular Linked List.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    
    if (top == NULL) {
        newNode->next = newNode;
    } else {
        newNode->next = top->next;
        top->next = newNode;
    }
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    struct Node* temp = top->next;
    int item = temp->data;
    
    if (top->next == top) {
        free(top);
        top = NULL;
    } else {
        top->next = temp->next;
        free(temp);
    }
    
    return item;
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    
    struct Node* temp = top->next;
    printf("Stack elements: ");
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != top->next);
    
    printf("\n");
}

int main() {
    push(5);
    push(15);
    push(25);
    display();
    printf("Popped element: %d\n", pop());
    display();
    return 0;
}