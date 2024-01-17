#include<stdio.h>	
#include<time.h>

int main(){
    int size;
    printf("Enter the size of an Array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of an Array: ");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    clock_t start = clock();
    int min=arr[0], max=arr[0];
    for(int i=0; i<size; i++){
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Minimum element of an Array is: %d\n", min);
    printf("Maximum element of an Array is: %d\n", max);
    printf("Time taken to find the minimum and maximum element of an Array is: %lf\n", time);
    return 0;
}
