/*
6. Multiply a given number to an input polynomial.
Input Polynomial: 5x^3 - 3x^2 + 2x^2 - 1
Input number: -2
Output: Output polynomial is: -10x^4 - 6x^2 - 4x^2 + 2
*/

#include <stdio.h>
#define MAX_DEGREE 10

void multiplyPolynomialByNumber(int poly[], int degree, int num, int result[]) {
    for (int i = 0; i <= degree; i++) {
        result[i] = poly[i] * num;
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
    int poly[MAX_DEGREE + 1] = {0};
    int result[MAX_DEGREE + 1] = {0};
    int degree, num;

    printf("Enter the highest degree of the polynomial: ");
    scanf("%d", &degree);

    printf("Enter coefficients for the polynomial (from x^0 to x^%d): ", degree);
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly[i]);
    }

    printf("Enter the number to multiply: ");
    scanf("%d", &num);

    multiplyPolynomialByNumber(poly, degree, num, result);
    printf("Output polynomial is: ");
    displayPolynomial(result, degree);

    return 0;
}