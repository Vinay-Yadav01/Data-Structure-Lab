#include <stdio.h>
#include <time.h>
#include <stdio.h>

#define SIZE 10
int top = -1, stack[SIZE];

int isFull()
{
    if (top == SIZE - 1)
        return 1;
    return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

void push(int x)
{
    if (isFull())
    {
        printf("\nOverflow!!");
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("\nUnderflow!!");
        return -1;
    }
    else
    {
        top = top - 1;
        return stack[top + 1];
    }
}

int ackermann(int m, int n){
    push(m);
    push(n);
    while (!isEmpty()){
        n = pop();
        m = pop();
        if (m == 0) n = n + 1;
        else if (n == 0){
            m = m - 1;
            n = 1;
        }
        else{
            push(m - 1);
            push(n);
            push(m);
            push(n - 1);
        }
    }
    return n;
}

int main()
{
    clock_t start = clock();
    int m,n;
    printf("Enter the values of m and n: ");
    scanf("%d %d", &m, &n);
    int result = ackermann(m,n);
    printf("Ackermann's Function Result: %d\n", result);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}