#include <stdio.h>
#include<time.h>

int main() {
    int size, element, i,found=0;
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
    
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            found = 1;
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
        }
    }
    if (found){
        printf("%d deleted successfully.\n", element);
        printf("Updated array: ");
        for (i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    } 
    else{
        printf("%d not found in the array.\n", element);
    }
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}
