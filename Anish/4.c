#include <stdio.h>

// Euclidean Algorithm to find GCD
int euclideanGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    printf("Enter two integers a and b: ");
    scanf("%d %d", &a, &b);

    // Euclidean Algorithm
    int gcd = euclideanGCD(a, b);
    printf("\nGCD of %d and %d using Euclidean Algorithm is: %d\n", a, b, gcd);

    // Extended Euclidean Algorithm
    int x, y;
    int gcd_ext = extendedEuclidean(a, b, &x, &y);
    printf("Using Extended Euclidean Algorithm:\n");
    printf("GCD: %d, x: %d, y: %d\n", gcd_ext, x, y);
    printf("Verification: %d*%d + %d*%d = %d\n", a, x, b, y, a*x + b*y);

    return 0;
}
