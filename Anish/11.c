#include <stdio.h>

// Swap helper function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate permutations
void generate_permutations(int arr[], int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);                 // Fix one element
        generate_permutations(arr, start + 1, end); // Permute remaining
        swap(&arr[start], &arr[i]);                 // Backtrack
    }
}

// Recursive function to generate combinations
void generate_combinations(int arr[], int n, int r, int index, int data[], int i) {
    // When r elements are chosen
    if (index == r) {
        for (int j = 0; j < r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    // When no more elements are left
    if (i >= n)
        return;

    // Include arr[i]
    data[index] = arr[i];
    generate_combinations(arr, n, r, index + 1, data, i + 1);

    // Exclude arr[i]
    generate_combinations(arr, n, r, index, data, i + 1);
}

int main() {
    int n, r;
    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nAll permutations of the array:\n");
    generate_permutations(arr, 0, n - 1);

    printf("\nEnter r for combinations: ");
    scanf("%d", &r);
    int data[r];
    printf("\nAll combinations of %d elements:\n", r);
    generate_combinations(arr, n, r, 0, data, 0);

    return 0;
}
