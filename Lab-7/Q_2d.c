#include <stdio.h>
#include <time.h>
#include <stdio.h>

#define SIZE 10
int top = -1, stack[SIZE];

int isFull(){
    if (top == SIZE - 1)
        return 1;
    return 0;
}

int isEmpty(){
    if (top == -1)
        return 1;
    return 0;
}

void push(int x){
    if (isFull()){
        printf("\nOverflow!!");
    }
    else{
        top = top + 1;
        stack[top] = x;
    }
}

int pop(){
    if (isEmpty()){
        printf("\nUnderflow!!");
        return -1;
    }
    else{
        top = top - 1;
        return stack[top + 1];
    }
}

void function2(int n);

void function1(int n)
{
    if (n > 0){
        printf("%d ", n);
        push(n - 1); // Push the next value onto the stack
        function2(pop()); // Call function2 with the popped value
    }
}

void function2(int n)
{
    if (n > 0){
        printf("%d ", n);
        push(n - 1); // Push the next value onto the stack
        function1(pop()); // Call function1 with the popped value
    }
}

int main()
{
    clock_t start = clock();
    push(5); // Push the initial value onto the stack
    function1(pop()); // Call function1 with the popped value
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f\n", time_spent);
    
    return 0;
}