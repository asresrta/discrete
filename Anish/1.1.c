#include <stdio.h>

int main() {
    int set1[100], set2[100], unionSet[200];
    int n1, n2, i, j, k = 0;
    int isDuplicate;

    // Input size and elements of Set 1
    printf("Enter number of elements in Set 1: ");
    scanf("%d", &n1);
    printf("Enter elements of Set 1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
        unionSet[k] = set1[i];
        k = k + 1;  // increment manually
    }

    // Input size and elements of Set 2
    printf("Enter number of elements in Set 2: ");
    scanf("%d", &n2);
    printf("Enter elements of Set 2:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);

        // Check if set2[i] is already in unionSet
        isDuplicate = 0;
        for (j = 0; j < k; j++) {
            if (set2[i] == unionSet[j]) {
                isDuplicate = 1;
                break;
            }
        }

        // If not duplicate, add to unionSet
        if (!isDuplicate) {
            unionSet[k] = set2[i];
            k = k + 1;  // increment manually
        }
    }

    // Print the union set
    printf("Union of the sets: { ");
    for (i = 0; i < k; i++) {
        printf("%d ", unionSet[i]);
    }
    printf("}\n");

    return 0;
}
 