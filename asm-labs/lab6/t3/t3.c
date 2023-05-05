#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int* t3_fun(int x0,size_t N);

int main(void){
    int x0;
    size_t N;
    scanf("%d %lu",&x0,&N);
    int *arr = t3_fun(x0, N);
    for(int i=0;i<N;i++)
        printf("%d ",arr[i]);
    free(arr);
    return 0;
}
