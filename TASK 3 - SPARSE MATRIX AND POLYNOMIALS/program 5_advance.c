/*
5. Evaluate a polynomial with a given value of 'X'.
*/

#include <stdio.h>
#include <math.h>
#define MAX_DEGREE 10

int evaluatePolynomial(int poly[], int degree, int x) {
    int result = 0;
    for (int i = 0; i <= degree; i++) {
        result += poly[i] * pow(x, i);
    }
    return result;
}

int main() {
    int poly[MAX_DEGREE + 1] = {0};
    int degree, x;

    printf("Enter the highest degree of the polynomial: ");
    scanf("%d", &degree);

    printf("Enter coefficients for the polynomial (from x^0 to x^%d): ", degree);
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly[i]);
    }

    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = evaluatePolynomial(poly, degree, x);
    printf("Result of evaluation: %d\n", result);

    return 0;
}