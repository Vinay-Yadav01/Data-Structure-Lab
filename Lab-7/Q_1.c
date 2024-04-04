#include <stdio.h>
#include<time.h>
#include "stack.h"

int main()
{
    clock_t start = clock();
    int choice;
    printf("\nPerform operations on the stack:");
    printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.Is Full\n5.Is Empty\n6.Top Element\n7.Size of Stack\n8.End");
    printf("\n\nEnter the choice: ");
    scanf("%d", &choice);
    while (choice != 8)
    {
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            printf("%d\n", isFull());
            break;
        case 5:
            printf("%d\n", isEmpty());
            break;
        case 6:
            topElement();
            break;
        case 7:
            printf("%d\n", top + 1);
            break;
        default:
            printf("\nInvalid choice!!");
        }

        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}