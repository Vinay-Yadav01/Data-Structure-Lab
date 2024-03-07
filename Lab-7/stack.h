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

void push()
{
    int x;
    if (isFull())
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        stack[top] = x;
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top = top - 1;
    }
}

void show()
{
    if (isEmpty())
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}

void topElement()
{
    if (isEmpty())
        printf("Stack is Empty\n");
    else
        printf("%d\n", stack[top]);
}