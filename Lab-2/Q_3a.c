#include<stdio.h>
#include<time.h>

int main(){
    int size;
    printf("Enter the size of the Array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the Element of the Array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    clock_t start = clock();
    for(int i=0;i<size;i++){
        int swapped = 0;
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped=1;
            }
        }
        if(swapped==0) break;
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken: %lf \n",time);
    return 0;
}