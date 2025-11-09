/*
7. Evaluate a postfix expression using stack and array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
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
    char postfix[MAX];
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    
    return 0;
}