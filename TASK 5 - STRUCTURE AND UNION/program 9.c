/*
9. Add and subtract two polynomials using structures.
*/

#include <stdio.h>
#define MAX_DEGREE 10

struct Polynomial {
    int coeff[MAX_DEGREE + 1];
    int degree;
};

void addPolynomials(struct Polynomial p1, struct Polynomial p2, struct Polynomial *result) {
    result->degree = (p1.degree > p2.degree) ? p1.degree : p2.degree;
    for (int i = 0; i <= result->degree; i++) {
        result->coeff[i] = p1.coeff[i] + p2.coeff[i];
    }
}

void subtractPolynomials(struct Polynomial p1, struct Polynomial p2, struct Polynomial *result) {
    result->degree = (p1.degree > p2.degree) ? p1.degree : p2.degree;
    for (int i = 0; i <= result->degree; i++) {
        result->coeff[i] = p1.coeff[i] - p2.coeff[i];
    }
}

void displayPolynomial(struct Polynomial p) {
    for (int i = p.degree; i >= 0; i--) {
        if (p.coeff[i] != 0) {
            printf("%dx^%d ", p.coeff[i], i);
            if (i != 0) printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    struct Polynomial p1 = {{0}, 0};
    struct Polynomial p2 = {{0}, 0};
    struct Polynomial sum = {{0}, 0};
    struct Polynomial diff = {{0}, 0};

    printf("Enter degree of polynomial 1: ");
    scanf("%d", &p1.degree);
    printf("Enter coefficients (from x^0 to x^%d): ", p1.degree);
    for (int i = 0; i <= p1.degree; i++) {
        scanf("%d", &p1.coeff[i]);
    }

    printf("Enter degree of polynomial 2: ");
    scanf("%d", &p2.degree);
    printf("Enter coefficients (from x^0 to x^%d): ", p2.degree);
    for (int i = 0; i <= p2.degree; i++) {
        scanf("%d", &p2.coeff[i]);
    }

    addPolynomials(p1, p2, &sum);
    subtractPolynomials(p1, p2, &diff);

    printf("Sum: ");
    displayPolynomial(sum);

    printf("Difference: ");
    displayPolynomial(diff);

    return 0;
}