/*
3. Convert the prefix and postfix notation of a given infix expression using stack and array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char symbol) {
    switch(symbol) {
        case '^': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        case '(': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item, x;
    
    push('(');
    strcat(infix, ")");
    
    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];
        
        if (item == '(') {
            push(item);
        } else if (isalnum(item)) {
            postfix[j++] = item;
        } else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } else {
            while (precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }
    
    postfix[j] = '\0';
}

void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    // Reverse the infix expression
    reverseString(infix);
    
    // Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    
    // Get postfix of reversed infix
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    
    // Reverse the postfix to get prefix
    reverseString(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}