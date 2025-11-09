/*
7. Multiply two polynomials using 1D array.
*/

#include <stdio.h>
#define MAX_DEGREE 10

void multiplyPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2) {
    int maxDegree = degree1 + degree2;

    for (int i = 0; i <= degree1; i++) {
        for (int j = 0; j <= degree2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

void displayPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%dx^%d ", poly[i], i);
            if (i != 0) {
                printf("+ ");
            }
        }
    }
    printf("\n");
}

int main() {
    int poly1[MAX_DEGREE + 1] = {0};
    int poly2[MAX_DEGREE + 1] = {0};
    int result[2 * MAX_DEGREE + 1] = {0};
    int degree1, degree2;

    printf("Enter the highest degree of polynomial 1: ");
    scanf("%d", &degree1);

    printf("Enter coefficients for polynomial 1 (from x^0 to x^%d): ", degree1);
    for (int i = 0; i <= degree1; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter the highest degree of polynomial 2: ");
    scanf("%d", &degree2);

    printf("Enter coefficients for polynomial 2 (from x^0 to x^%d): ", degree2);
    for (int i = 0; i <= degree2; i++) {
        scanf("%d", &poly2[i]);
    }

    multiplyPolynomials(poly1, poly2, result, degree1, degree2);
    printf("Product of polynomials: ");
    displayPolynomial(result, degree1 + degree2);

    return 0;
}