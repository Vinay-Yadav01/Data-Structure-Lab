#include <stdio.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    clock_t start = clock();
    int size;
    printf("Enter a size: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter element to be searched: ");
    scanf("%d", &key);
    int linearSearchIndex = linearSearch(arr, size, key);
    printf("Linear Search: ");
    if (linearSearchIndex != -1) {
        printf("Element found at index %d\n", linearSearchIndex);
    } else {
        printf("Element not found\n");
    }
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time Taken by Linear Search: %lf \n", time);

    start = clock();
    int binarySearchIndex = binarySearch(arr, 0, size - 1, key);
    printf("Binary Search: ");
    if (binarySearchIndex != -1) {
        printf("Element found at index %d\n", binarySearchIndex);
    } else {
        printf("Element not found\n");
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time Taken by Binary Search: %lf \n", time);
    return 0;
}