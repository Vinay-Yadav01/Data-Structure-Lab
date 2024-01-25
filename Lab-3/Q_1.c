#include <stdio.h>
#include<time.h>

void input(int a[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void print(int a[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void prod(int a[4][4],int b[4][4],int ans[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int temp=0;
            for(int k=0;k<4;k++){
                temp+=(a[i][k]*b[j][k]);
            }
            ans[i][j]=temp;
        }
    }
}

int main(){
    clock_t start = clock();
    int a[4][4],b[4][4],ans[4][4];
    printf("Enter the elements of first matrix A: \n");
    input(a);
    printf("Enter the elements of second matrix B: \n");
    input(b);
    printf("\nMatrix A: \n");
    print(a);
    printf("\nMatrix B: \n");
    print(b);
    prod(a,b,ans);
    printf("Product of matrix A and matrix B: \n \n");
    print(ans);
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken: %lf \n",time);
    return 0;
}