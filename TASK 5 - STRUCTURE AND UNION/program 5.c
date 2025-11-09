/*
5. Create a structure named "Complex" to represent a complex number with real and imaginary parts. Write a C program to add and multiply two complex numbers.
*/

#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

struct Complex add(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex multiply(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    struct Complex c1, c2, sum, product;

    printf("Enter Complex Number 1 (real imag): ");
    scanf("%f %f", &c1.real, &c1.imag);

    printf("Enter Complex Number 2 (real imag): ");
    scanf("%f %f", &c2.real, &c2.imag);

    sum = add(c1, c2);
    product = multiply(c1, c2);

    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Product: %.2f + %.2fi\n", product.real, product.imag);
    return 0;
}