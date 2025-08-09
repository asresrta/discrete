#include <stdio.h>

#define MAX 10

void inputRelation(int relation[MAX][MAX], int n);
void displayRelation(int relation[MAX][MAX], int n);
int isReflexive(int relation[MAX][MAX], int n);
int isSymmetric(int relation[MAX][MAX], int n);
int isAntisymmetric(int relation[MAX][MAX], int n);
int isTransitive(int relation[MAX][MAX], int n);
void checkEquivalence(int relation[MAX][MAX], int n);

int main() {
    int n;
    int relation[MAX][MAX];

    printf("Enter the number of elements in the set (<= %d): ", MAX);
    scanf("%d", &n);

    printf("\nEnter the relation matrix (%d x %d):\n", n, n);
    inputRelation(relation, n);

    printf("\nThe relation matrix is:\n");
    displayRelation(relation, n);

    // Checking properties
    printf("\nProperties of the relation:\n");
    printf("Reflexive: %s\n", isReflexive(relation, n) ? "Yes" : "No");
    printf("Symmetric: %s\n", isSymmetric(relation, n) ? "Yes" : "No");
    printf("Antisymmetric: %s\n", isAntisymmetric(relation, n) ? "Yes" : "No");
    printf("Transitive: %s\n", isTransitive(relation, n) ? "Yes" : "No");

    checkEquivalence(relation, n);

    return 0;
}

void inputRelation(int relation[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &relation[i][j]);
        }
    }
}

void displayRelation(int relation[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", relation[i][j]);
        }
        printf("\n");
    }
}

int isReflexive(int relation[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        if (relation[i][i] != 1)
            return 0;
    }
    return 1;
}

int isSymmetric(int relation[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (relation[i][j] != relation[j][i])
                return 0;
        }
    }
    return 1;
}

int isAntisymmetric(int relation[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && relation[i][j] == 1 && relation[j][i] == 1)
                return 0;
        }
    }
    return 1;
}

int isTransitive(int relation[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (relation[i][j]) {
                for (int k = 0; k < n; k++) {
                    if (relation[j][k] && !relation[i][k])
                        return 0;
                }
            }
        }
    }
    return 1;
}

void checkEquivalence(int relation[MAX][MAX], int n) {
    if (isReflexive(relation, n) && isSymmetric(relation, n) && isTransitive(relation, n))
        printf("\nThe relation is an **Equivalence Relation**.\n");
    else
        printf("\nThe relation is **NOT an Equivalence Relation**.\n");
}
