#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
 
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 
char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; 
}

void infixToPostfix(char s[]) {
    char result[1000];
    int resultIndex = 0;
    int len = strlen(s);
    char stack[1000];
    int top = -1;
 
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex++] = c;
        }
        else if (c == '(') {
            stack[++top] = c;
        }
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                result[resultIndex++] = stack[top--];
            }
            top--; 
        }
        else {
            while (top >= 0 && (prec(s[i]) < prec(stack[top]) ||
                                       prec(s[i]) == prec(stack[top]) &&
                                           associativity(s[i]) == 'L')) {
                result[resultIndex++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top >= 0) {
        result[resultIndex++] = stack[top--];
    }
    result[resultIndex] = '\0';
    printf("Postfix expression: %s\n", result);
}

int main() {
    clock_t start = clock();
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("Infix expression: %s\n", exp);
    infixToPostfix(exp); 
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}