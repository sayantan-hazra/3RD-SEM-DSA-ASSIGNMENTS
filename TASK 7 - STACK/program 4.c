/*
4. Evaluate a postfix expression using stack and linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int item = temp->data;
    top = top->next;
    free(temp);
    return item;
}

int evaluatePostfix(char postfix[]) {
    int i, operand1, operand2, result;
    
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            operand2 = pop();
            operand1 = pop();
            
            switch(postfix[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': 
                    result = 1;
                    for (int j = 0; j < operand2; j++)
                        result *= operand1;
                    break;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char postfix[100];
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    
    return 0;
}