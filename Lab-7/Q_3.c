#include <stdio.h>
#include <time.h>
#include<string.h>
#include "stack.h"

void infixToPostfix(char str[]){
    char ans[strlen(str)];
    for(int i=0;i<strlen(str);i++){
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            ans[resultIndex++] = c;
        }
    }
}

int main()
{
    clock_t start = clock();
    int size;
    printf("Enter the size of Expression: ");
    scanf("%d",&size);
    char str[size];
    scanf("%s",str);
    infixToPostfix(str);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}