#include <stdio.h>

int main() {
    int set1[100], set2[100], intersection[100];
    int n1, n2, i, j, k = 0;
    int isCommon;

    // Input sizes in a single line
    printf("Enter the sizes of Set 1 and Set 2: ");
    scanf("%d %d", &n1, &n2);

    // Input elements of Set 1
    printf("Enter elements of Set 1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
    }

    // Input elements of Set 2
    printf("Enter elements of Set 2:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);
    }

    // Find intersection
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (set1[i] == set2[j]) {
                // Check if already added
                isCommon = 0;
                for (int m = 0; m < k; m++) {
                    if (intersection[m] == set1[i]) {
                        isCommon = 1;
                        break;
                    }
                }

                if (!isCommon) {
                    intersection[k] = set1[i];
                    k = k + 1;  // manually increment
                }
            }
        }
    }

    // Print intersection
    printf("Intersection of the sets: { ");
    for (i = 0; i < k; i++) {
        printf("%d ", intersection[i]);
    }
    printf("}\n");

    return 0;
}
