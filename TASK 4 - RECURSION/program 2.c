/*
2. Find sum of digits of a given number using recursion.
*/

#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + sumOfDigits(n / 10);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Sum of digits of %d is %d\n", num, sumOfDigits(num));
    return 0;
}