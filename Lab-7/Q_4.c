#include <stdio.h>
#include <time.h>
#include "stack.h"

int main()
{
    clock_t start = clock();
    
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}