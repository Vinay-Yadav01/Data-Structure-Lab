#include <stdio.h>
#include<time.h>
#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], size, position, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    printf("Enter the position of the element to be deleted: ");
    scanf("%d", &position);

    // Check if the position is valid
    if (position < 1 || position > size) {
        printf("Invalid position!\n");
    } else {
        // Shift the elements to the left from the given position
        for (i = position - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        // Decrease the size of the array
        size--;
        // Print the updated array
        printf("Array after deleting the element:\n");
        for (i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}
