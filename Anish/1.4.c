#include <stdio.h>

int main() {
    int set1[100], set2[100];
    int n1, n2, i, j;

    // Input sizes in one line
    printf("Enter sizes of Set 1 and Set 2: ");
    scanf("%d %d", &n1, &n2);

    // Input Set 1
    printf("Enter elements of Set 1:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
    }

    // Input Set 2
    printf("Enter elements of Set 2:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);
    }

    // Display Cartesian Product
    printf("Cartesian Product :\n{ ");
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            printf("(%d,%d) ", set1[i], set2[j]);
        }
    }
    printf("}\n");

    return 0;
}
