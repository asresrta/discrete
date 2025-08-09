#include <stdio.h>

// Addition using bitwise operators
int add(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// Multiplication using bitwise and add
int multiply(int a, int b) {
    int result = 0;
    while (b > 0) {
        if (b & 1)
            result = add(result, a);
        a <<= 1;
        b >>= 1;
    }
    return result;
}

// Division using bitwise operators
int divide(int dividend, int divisor) {
    if (divisor == 0) {
        printf("Error: Division by zero!\n");
        return -1;
    }
    int quotient = 0;
    int temp = 0;
    for (int i = 31; i >= 0; i--) {
        temp <<= 1;
        temp |= (dividend >> i) & 1;
        if (temp >= divisor) {
            temp -= divisor;
            quotient |= (1 << i);
        }
    }
    return quotient;
}

int main() {
    int a, b;
    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);

    printf("Addition: %d\n", add(a, b));
    printf("Multiplication: %d\n", multiply(a, b));
    printf("Division: %d\n", divide(a, b));

    return 0;
}
