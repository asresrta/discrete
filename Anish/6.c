#include <stdio.h>

#define MAX 10  // Max size of matrix

void inputMatrix(int mat[MAX][MAX], int rows, int cols, char name) {
    printf("Enter elements for Matrix %c (0 or 1 only):\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c[%d][%d]: ", name, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX][MAX], int rows, int cols, char *title) {
    printf("\n%s:\n", title);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void booleanJoin(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] | B[i][j];
}

void booleanProduct(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] & B[i][j];
}

void booleanMatrixMultiplication(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] |= (A[i][k] & B[k][j]);
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rows, cols;

    printf("Enter number of rows and columns :");
    scanf("%d %d", &rows, &cols);

    inputMatrix(A, rows, cols, 'A');
    inputMatrix(B, rows, cols, 'B');

    booleanJoin(A, B, result, rows, cols);
    printMatrix(result, rows, cols, "Join (A OR B)");

    booleanProduct(A, B, result, rows, cols);
    printMatrix(result, rows, cols, "Product (A AND B)");

    // For boolean matrix multiplication: A[rows x cols], B[cols x cols]
    booleanMatrixMultiplication(A, B, result, rows, cols, cols);
    printMatrix(result, rows, cols, "Boolean Matrix Product (A * B)");

    return 0;
}
