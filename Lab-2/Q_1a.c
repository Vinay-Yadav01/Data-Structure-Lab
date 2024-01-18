#include<stdio.h>
#include<time.h>

int main(){
    int size,search,flag=0,i;
    printf("Enter the size of the Array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the Unique elements of the Array: ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    clock_t start = clock();
    printf("Enter the elemnt to be Search: ");
    scanf("%d",&search);
    for(i=0;i<size;i++){
        if(arr[i]==search) {
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("Number %d found at index %d\n", search, i);
    }
    else{
        printf("%d is NOT present in the Array\n",search);
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken: %lf \n",time);
    return 0;
}

