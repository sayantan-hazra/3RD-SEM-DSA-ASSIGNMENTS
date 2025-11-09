/*
6. Convert the prefix and postfix notation of a given infix expression using stack and Linked List.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    char item = temp->data;
    top = top->next;
    free(temp);
    return item;
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
            while (top != NULL && precedence(top->data) >= precedence(item)) {
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
    char postfix[100];
    infixToPostfix(infix, postfix);
    
    // Reverse the postfix to get prefix
    reverseString(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[100], postfix[100], prefix[100];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}