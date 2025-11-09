/*
3. Represent and add two polynomials using SLLs.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node *next;
};

struct Node *createPolynomial() {
    struct Node *head = NULL;
    struct Node *last = NULL;
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &newNode->coeff, &newNode->exp);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    return head;
}

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *last = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if (poly1->exp > poly2->exp) {
            newNode->coeff = poly1->coeff;
            newNode->exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            newNode->coeff = poly2->coeff;
            newNode->exp = poly2->exp;
            poly2 = poly2->next;
        } else {
            newNode->coeff = poly1->coeff + poly2->coeff;
            newNode->exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (result == NULL) {
            result = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    while (poly1 != NULL) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = poly1->coeff;
        newNode->exp = poly1->exp;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = poly2->coeff;
        newNode->exp = poly2->exp;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
        poly2 = poly2->next;
    }

    return result;
}

void displayPolynomial(struct Node *poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    printf("Enter Polynomial 1:\n");
    struct Node *poly1 = createPolynomial();
    printf("Enter Polynomial 2:\n");
    struct Node *poly2 = createPolynomial();

    struct Node *sum = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    displayPolynomial(sum);
    return 0;
}