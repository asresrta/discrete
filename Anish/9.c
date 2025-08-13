#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

// Operator precedence
int precedence(char *op) {
    if (strcmp(op, "!") == 0) return 5;
    if (strcmp(op, "&&") == 0) return 4;
    if (strcmp(op, "||") == 0) return 3;
    if (strcmp(op, "->") == 0) return 2;
    if (strcmp(op, "<->") == 0) return 1;
    return 0;
}

// Apply operator
int applyOp(char *op, int a, int b) {
    if (strcmp(op, "&&") == 0) return a && b;
    if (strcmp(op, "||") == 0) return a || b;
    if (strcmp(op, "->") == 0) return (!a) || b;
    if (strcmp(op, "<->") == 0) return a == b;
    return 0;
}

// Apply NOT
int applyNot(int a) {
    return !a;
}

// Convert infix to postfix using Shunting Yard
void infixToPostfix(char *expr, char output[MAX][MAX], int *outCount) {
    char stack[MAX][MAX];
    int top = -1;
    char token[MAX];
    int i = 0, j = 0;
    *outCount = 0;

    while (*expr) {
        if (isspace(*expr)) { expr++; continue; }

        // Variables
        if (*expr == 'P' || *expr == 'Q' || *expr == 'R') {
            sprintf(output[(*outCount)++], "%c", *expr);
            expr++;
        }
        // Operators
        else if (*expr == '!') {
            strcpy(token, "!");
            strcpy(stack[++top], token);
            expr++;
        }
        else if (*expr == '&' && *(expr+1) == '&') {
            strcpy(token, "&&");
            while (top >= 0 && precedence(stack[top]) >= precedence(token))
                strcpy(output[(*outCount)++], stack[top--]);
            strcpy(stack[++top], token);
            expr += 2;
        }
        else if (*expr == '|' && *(expr+1) == '|') {
            strcpy(token, "||");
            while (top >= 0 && precedence(stack[top]) >= precedence(token))
                strcpy(output[(*outCount)++], stack[top--]);
            strcpy(stack[++top], token);
            expr += 2;
        }
        else if (*expr == '-' && *(expr+1) == '>') {
            strcpy(token, "->");
            while (top >= 0 && precedence(stack[top]) >= precedence(token))
                strcpy(output[(*outCount)++], stack[top--]);
            strcpy(stack[++top], token);
            expr += 2;
        }
        else if (*expr == '<' && *(expr+1) == '-' && *(expr+2) == '>') {
            strcpy(token, "<->");
            while (top >= 0 && precedence(stack[top]) >= precedence(token))
                strcpy(output[(*outCount)++], stack[top--]);
            strcpy(stack[++top], token);
            expr += 3;
        }
        // Parentheses
        else if (*expr == '(') {
            strcpy(stack[++top], "(");
            expr++;
        }
        else if (*expr == ')') {
            while (top >= 0 && strcmp(stack[top], "(") != 0)
                strcpy(output[(*outCount)++], stack[top--]);
            top--; // pop '('
            expr++;
        }
        else {
            expr++;
        }
    }

    while (top >= 0)
        strcpy(output[(*outCount)++], stack[top--]);
}

// Evaluate postfix
int evalPostfix(char output[MAX][MAX], int outCount, int P, int Q, int R) {
    int stack[MAX], top = -1;
    for (int i = 0; i < outCount; i++) {
        if (strcmp(output[i], "P") == 0) stack[++top] = P;
        else if (strcmp(output[i], "Q") == 0) stack[++top] = Q;
        else if (strcmp(output[i], "R") == 0) stack[++top] = R;
        else if (strcmp(output[i], "!") == 0) {
            int a = stack[top--];
            stack[++top] = applyNot(a);
        }
        else {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = applyOp(output[i], a, b);
        }
    }
    return stack[top];
}

int main() {
    int numPremises;
    char premises[10][MAX];
    char conclusion[MAX];
    char postfixPrem[10][MAX][MAX], postfixConc[MAX][MAX];
    int premCount[10], concCount;

    printf("Enter number of premises: ");
    scanf("%d", &numPremises);
    getchar();

    for (int i = 0; i < numPremises; i++) {
        printf("Enter premise %d: ", i + 1);
        fgets(premises[i], MAX, stdin);
        premises[i][strcspn(premises[i], "\n")] = 0;
        infixToPostfix(premises[i], postfixPrem[i], &premCount[i]);
    }

    printf("Enter conclusion: ");
    fgets(conclusion, MAX, stdin);
    conclusion[strcspn(conclusion, "\n")] = 0;
    infixToPostfix(conclusion, postfixConc, &concCount);

    int valid = 1;

    printf("\nP Q R");
    for (int i = 0; i < numPremises; i++) printf(" Prem%d", i + 1);
    printf(" Conc\n");
    printf("--------------------------------------\n");

    for (int P = 0; P <= 1; P++) {
        for (int Q = 0; Q <= 1; Q++) {
            for (int R = 0; R <= 1; R++) {
                int allPremTrue = 1;
                int premVals[10];

                for (int i = 0; i < numPremises; i++) {
                    premVals[i] = evalPostfix(postfixPrem[i], premCount[i], P, Q, R);
                    if (!premVals[i]) allPremTrue = 0;
                }

                int concVal = evalPostfix(postfixConc, concCount, P, Q, R);

                printf("%d %d %d", P, Q, R);
                for (int i = 0; i < numPremises; i++) printf("    %d", premVals[i]);
                printf("    %d\n", concVal);

                if (allPremTrue && !concVal) valid = 0;
            }
        }
    }

    if (valid) printf("\nThe argument is VALID.\n");
    else printf("\nThe argument is INVALID.\n");

    return 0;
}
