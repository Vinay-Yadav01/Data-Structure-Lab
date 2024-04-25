#include <stdio.h>
#include <time.h>

void merge(int* arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++){
        R[i] = arr[m + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int l, int r){
    if (l>=r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}


int main(){
    clock_t start = clock();
    int num;
    printf("Enter a size: ");
    scanf("%d", &num);
    int *arr = (int *)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }    
    mergeSort(arr, 0, num-1);
    for (int i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime Taken: %lf \n", time);
    return 0;
}