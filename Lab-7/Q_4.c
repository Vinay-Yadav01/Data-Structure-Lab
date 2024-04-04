#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
struct Stack {
    int top;
    int capacity;
    int* array;
};
 
struct Stack* createStack(int capacity)
{
    struct Stack* stack
        = (struct Stack*)malloc(sizeof(struct Stack));
 
    if (!stack)
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
    stack->array
        = (int*)malloc(stack->capacity * sizeof(int));
 
    if (!stack->array)
        return NULL;
 
    return stack;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
 
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

int evaluate(char* exp)
{
    struct Stack* stack = createStack(strlen(exp));
    int i;
    if (!stack)
        return -1;
    for (i = 0; exp[i]; ++i) {
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i]) {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}
int main()
{
    clock_t start = clock();
    char exp[] = "5968*/+";
    printf("Postfix evaluation: %d\n", evaluate(exp));
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}