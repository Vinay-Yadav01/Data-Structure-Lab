#include <stdio.h>
#include<time.h>

void input(int a[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&a[i][j]);
        }
    }
}

void print(int a[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[5][5],int a_t[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            a_t[i][j]=a[j][i];
        }
    }
}

void prod(int a[5][5],int a_t[5][5],int ans[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int temp=0;
            for(int k=0;k<5;k++){
                temp+=(a[i][k]*a_t[j][k]);
            }
            ans[i][j]=temp;
        }
    }
}


int orthogonal(int ans[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if((i!=j && ans[i][j]!=0) || (i==j && ans[i][j]!=1)) return 0;
        }
    }
    return 1;
}

int main(){
    clock_t start = clock();
    int a[5][5],a_t[5][5],ans[5][5];
    printf("Enter the elements of matrix a: \n");
    input(a);
    printf("\nMatrix A: \n");
    print(a);
    transpose(a,a_t);
    printf("\nTranspose of Matrix a(a_t): \n");
    print(a_t);
    prod(a,a_t,ans);
    printf("Product of matrix a and matrix a_t: \n \n");
    print(ans);
    int check = orthogonal(ans);
    if(check==1){
        printf("Matrix A is Orthogonal\n");
    }
    else{
        printf("Matrix A is NOT Orthogonal\n");
    }
    clock_t end = clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;    
    printf("Time Taken: %lf \n",time);
    return 0;
}