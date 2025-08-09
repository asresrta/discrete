#include <stdio.h>

int main() {
    int set1[100], set2[100], diff[100];
    int n1, n2, i, j, k = 0, found;

    // Input sizes in one line
    printf("Enter sizes of Set 1 and Set 2: ");
    scanf("%d %d", &n1, &n2);

    // Input Set 1
    printf("Enter elements of Set 1:");
    for (i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
    }

    // Input Set 2
    printf("Enter elements of Set 2:");
    for (i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);
    }

    // Find Set1 - Set2
    for (i = 0; i < n1; i++) {
        found = 0;
        for (j = 0; j < n2; j++) {
            if (set1[i] == set2[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            diff[k] = set1[i];
            k = k + 1;
        }
    }

    // Print result
    printf("Difference: { ");
    for (i = 0; i < k; i++) {
        printf("%d ", diff[i]);
    }
    printf("}\n");

    return 0;
}
