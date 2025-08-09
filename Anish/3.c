#include <stdio.h>

int main() {
    float a[20], b[20], c[20];
    int n, i;

    // Input number of elements
    printf("Enter the number of elements in the fuzzy sets: ");
    scanf("%d", &n);

    // Input membership values for set A
    printf("Enter membership values for set A:\n");
    for (i = 0; i < n; i++) {
        printf("A[%d] = ", i);
        scanf("%f", &a[i]);
    }

    // Input membership values for set B
    printf("Enter membership values for set B:\n");
    for (i = 0; i < n; i++) {
        printf("B[%d] = ", i);
        scanf("%f", &b[i]);
    }

    // Fuzzy Union
    printf("\nFuzzy Union (A U B):\n");
    for (i = 0; i < n; i++) {
        c[i] = (a[i] > b[i]) ? a[i] : b[i];
        printf("Element %d : %.2f\n", i, c[i]);
    }

    // Fuzzy Intersection
    printf("\nFuzzy Intersection:\n");
    for (i = 0; i < n; i++) {
        c[i] = (a[i] < b[i]) ? a[i] : b[i];
        printf("Element %d : %.2f\n", i, c[i]);
    }

    // Fuzzy Complement of Set A
    printf("\nFuzzy Complement of Set A (~A):\n");
    for (i = 0; i < n; i++) {
        c[i] = 1 - a[i];
        printf("Element %d : %.2f\n", i, c[i]);
    }

    printf("\nFuzzy Complement of Set B (~B):\n");
    for (i = 0; i < n; i++) {
        c[i] = 1 - b[i];
        printf("Element %d : %.2f\n", i, c[i]);
    }

    return 0;
}
