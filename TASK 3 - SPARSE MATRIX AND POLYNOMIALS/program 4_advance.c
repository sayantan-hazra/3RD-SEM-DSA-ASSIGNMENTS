/*
4. Find the 'zero-coeff's of the polynomials (those indices whose co-efficient are 0).
Input Polynomial: 5x^3 - 3x^2 + 2x^2
Output: Zero-coeffs of the given polynomial are: 4,1,0
*/

#include <stdio.h>
#define MAX_DEGREE 10

void findZeroCoeffs(int poly[], int degree) {
    printf("Zero-coeffs of the given polynomial are: ");
    for (int i = degree; i >= 0; i--) {
        if (poly[i] == 0) {
            printf("%d, ", i);
        }
    }
    printf("\n");
}

int main() {
    int poly[MAX_DEGREE + 1] = {0};
    int degree;

    printf("Enter the highest degree of the polynomial: ");
    scanf("%d", &degree);

    printf("Enter coefficients for the polynomial (from x^0 to x^%d): ", degree);
    for (int i = 0; i <= degree; i++) {
        scanf("%d", &poly[i]);
    }

    findZeroCoeffs(poly, degree);

    return 0;
}