#include <stdio.h>
#include<time.h>
#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];   
    int size, position, element;   
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    printf("Enter the position to insert the element: ");
    scanf("%d", &position);
    
    if (position < 0 || position > size) {
        printf("Invalid position!\n");
        return 0;
    }   
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    // Shift elements to the right from position to end
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    } 
    // Insert the element at the given position
    arr[position] = element;    
    size++; // Increase the size of the array    
    printf("Array after inserting the element:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); 
    clock_t end = clock();
    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_taken);
    return 0;
}
