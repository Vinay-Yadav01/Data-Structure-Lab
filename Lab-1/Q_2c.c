#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, search, flag = 0;
    int *arr;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    printf("Enter the number to search: ");
    scanf("%d", &search);
    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            flag = 1;
            break;
        }
    }
    if (flag){
        printf("Number %d found at index %d\n", search, i);
    } 
    else{
        printf("Number %d not found in the array\n", search);
    }
    free(arr);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to search the element in the array is: %lf\n", time);
    return 0;
}
