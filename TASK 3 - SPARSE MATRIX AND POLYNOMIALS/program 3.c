/*
3. Add and subtract two polynomials using 1D array.
*/

#include <stdio.h>
#define MAX_DEGREE 10

void addPolynomials(int poly1[], int poly2[], int result[], int degree) {
    for (int i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}

void subtractPolynomials(int poly1[], int poly2[], int result[], int degree) {
    for (int i = 0; i <= degree; i++) {
        result[i] = poly1[i] - poly2[i];
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
    int poly1[MAX_DEGREE + 1] = {0}; // Initialize all coefficients to 0
    int poly2[MAX_DEGREE + 1] = {0};
    int result[MAX_DEGREE + 1] = {0};
    int degree;

    printf("Enter the highest degree of the polynomials: ");
    scanf("%d", &degree);

    printf("Enter coefficients for polynomial 1 (from x^0 to x^%d): ", degree);
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly1[i]);
    }

    printf("Enter coefficients for polynomial 2 (from x^0 to x^%d): ", degree);
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly2[i]);
    }

    addPolynomials(poly1, poly2, result, degree);
    printf("Sum of polynomials: ");
    displayPolynomial(result, degree);

    subtractPolynomials(poly1, poly2, result, degree);
    printf("Difference of polynomials: ");
    displayPolynomial(result, degree);

    return 0;
}