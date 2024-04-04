#include <stdio.h>
#include <time.h>

void towerOfHanoi(int disk , char from, char to, char aux){
    if(disk==0){
        return;
    }
    towerOfHanoi(disk-1,from,aux,to);
    printf("Move %d disk from %c to %c.\n",disk,from,to);
    towerOfHanoi(disk-1,aux,to,from);
}

int main()
{
    clock_t start = clock();
    int disk;
    printf("Enter number of Disk: ");
    scanf("%d" ,&disk);
    char from = 'A', aux='B', to='C';
    towerOfHanoi(disk,from,to,aux);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f\n", time_spent);
    return 0;
}