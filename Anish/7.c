#include <stdio.h>
#define MAX 1000

// Read a number and store digits in reverse order (least significant digit first)
int readNumber(int num[]) {
    char ch;
    int length = 0;

    printf("Enter a large integer : ");

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            // Shift everything right and add new digit
            for (int i = length; i > 0; i--) {
                num[i] = num[i - 1];
            }
            num[0] = ch - '0';
            length++;
        }
    }

    return length;
}

// Add two large numbers stored as digit arrays
int addLargeIntegers(int a[], int lenA, int b[], int lenB, int result[]) {
    int maxLen = (lenA > lenB) ? lenA : lenB;
    int carry = 0;

    for (int i = 0; i < maxLen; i++) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry) {
        result[maxLen] = carry;
        maxLen++;
    }

    return maxLen;
}

void printNumber(int num[], int len) {
    for (int i = len - 1; i >= 0; i--)
        printf("%d", num[i]);
    printf("\n");
}

int main() {
    int a[MAX], b[MAX], result[MAX];
    int lenA = 0, lenB = 0, lenResult;

    printf("First number:\n");
    lenA = readNumber(a);

    printf("Second number:\n");
    lenB = readNumber(b);

    lenResult = addLargeIntegers(a, lenA, b, lenB, result);

    printf("\nSum: ");
    printNumber(result, lenResult);

    return 0;
}
