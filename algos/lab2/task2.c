// вариант 15: рекурсивно записать в массив
// элементы последовательности an = 3^(n+1)/n!

#include <stdio.h>


double task2(double* arr,int n){
    if(n==0){
        arr[0]=3.0;
        return 3.0;
    }
    arr[n] = 3.0/((double)n)*task2(arr,n-1);
    return arr[n];
}

int main(void){
    double arr[6];
    task2(arr,5);
    for(int i=0;i<6;i++)
        printf("%lf ",arr[i]);
    return 0;
}

// результат выполнения:
// 3.000000 9.000000 13.500000 13.500000 10.125000 6.075000
