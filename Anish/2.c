#include <stdio.h>

// Function to compute floor of a number
int floorFunc(float num) {
    int intPart = (int)num;
    return (num >= 0 || num == intPart) ? intPart : intPart - 1;
}

// Function to compute ceiling of a number
int ceilFunc(float num) {
    int intPart = (int)num;
    return (num <= 0 || num == intPart) ? intPart : intPart + 1;
}

int main() {
    float num;

    printf("Enter a floating point number: ");
    scanf("%f", &num);

    printf("Floor of %.2f is: %d\n", num, floorFunc(num));
    printf("Ceiling of %.2f is: %d\n", num, ceilFunc(num));

    return 0;
}
