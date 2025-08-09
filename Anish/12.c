#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ---------- Randomized Linear Search ----------
int randomized_linear_search(int arr[], int n, int key) {
    int checked[n];
    for (int i = 0; i < n; i++) checked[i] = 0; // Track visited indices

    int count = 0;
    while (count < n) {
        int idx = rand() % n; // Random index
        if (checked[idx]) continue; // Skip already visited
        checked[idx] = 1;
        count++;
        if (arr[idx] == key)
            return idx; // Found the element
    }
    return -1;
}

// ---------- Randomized QuickSort ----------
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    // Random pivot selection
    int randomPivot = low + rand() % (high - low + 1);
    swap(&arr[randomPivot], &arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void randomized_quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        randomized_quick_sort(arr, low, pi - 1);
        randomized_quick_sort(arr, pi + 1, high);
    }
}

// ---------- Monte Carlo Algorithm for π ----------
double monte_carlo_pi(long long iterations) {
    long long inside_circle = 0;
    for (long long i = 0; i < iterations; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1.0)
            inside_circle++;
    }
    return (4.0 * inside_circle) / iterations;
}

// ---------- Main Function ----------
int main() {
    srand(time(0));

    // 1. Randomized Linear Search
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter key to search: ");
    scanf("%d", &key);

    int index = randomized_linear_search(arr, n, key);
    if (index != -1)
        printf("Key %d found at index %d using randomized linear search.\n", key, index);
    else
        printf("Key %d not found.\n", key);

    // 2. Randomized QuickSort
    printf("\nArray before Randomized QuickSort:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    randomized_quick_sort(arr, 0, n - 1);

    printf("Array after Randomized QuickSort:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // 3. Monte Carlo Approximation of π
    long long iterations;
    printf("\nEnter number of iterations for Monte Carlo pie approximation: ");
    scanf("%lld", &iterations);
    double pi_approx = monte_carlo_pi(iterations);
    printf("Approximated value of pie using %lld iterations: %f\n", iterations, pi_approx);

    return 0;
}
