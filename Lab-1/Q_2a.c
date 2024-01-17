#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    clock_t start = clock();
    int *arr = (int*)malloc(size * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Traversing the array from first to last:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to traverse the array from first to last is: %lf\n", time);
    free(arr);  
    return 0;
}
