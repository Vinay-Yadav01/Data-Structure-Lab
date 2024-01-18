#include <stdio.h>
#include<time.h>

int main() {
    int size, element, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    printf("Enter the element to be deleted: ");
    scanf("%d", &element);
    
    int index=-1;
    for (i = 0; i < size; i++) {
        if(arr[i]==element){
            index=i;
            for (i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        }
    }
    // Print the updated array
    printf("Array after deleting the element:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}
