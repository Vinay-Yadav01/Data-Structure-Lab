#include <stdio.h>
#include <time.h>
#define SIZE 10

int top = -1, stack[SIZE];


void push(int num)
{
    if (top==SIZE-1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        top = top + 1;
        stack[top] = num;
    }
}

void pop()
{
    if (top==-1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        
        top = top - 1;
    }
}

void show()
{
    if (top==-1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        for (int i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    clock_t start = clock();
    int number;
    printf("Enter Number: ");
    scanf("%d",&number);
    while(number){
        push(number--);
        show();
        pop();
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}