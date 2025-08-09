#include <stdio.h>

// Recursive function for a^n mod m
int mod_pow(int base, int exp, int mod) {
    if (exp == 0)
        return 1;
    int half = mod_pow(base, exp / 2, mod);
    int result = (1LL * half * half) % mod;
    if (exp % 2 == 1)
        result = (1LL * result * base) % mod;
    return result;
}

// Recursive linear search
int linear_search(int arr[], int size, int key, int index) {
    if (index >= size)
        return -1;
    if (arr[index] == key)
        return index;
    return linear_search(arr, size, key, index + 1);
}

int main() {
    int a, b, n, m;

    // Modular exponentiation
    printf("Enter values for a, b, n, m: ");
    scanf("%d %d %d %d", &a, &b, &n, &m);

    int a_pow = mod_pow(a, n, m);
    int b_pow = mod_pow(b, n, m);

    printf("a^n mod m = %d\n", a_pow);
    printf("b^n mod m = %d\n", b_pow);

    // Recursive Linear Search
    int arr[100], size, key;
    printf("\nEnter array size: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    int result = linear_search(arr, size, key, 0);

    if (result != -1)
        printf("Key found at index %d\n", result);
    else
        printf("Key not found\n");

    return 0;
}
