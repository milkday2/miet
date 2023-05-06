#include <stddef.h>
#include <stdio.h>

void t5_fun(double* x,double* y,double* z,size_t size);

int main(void){
    double x[]={1.0,2.0,3.0,4.0,5.0};
    double y[]={5.0,4.0,3.0,2.0,1.0};
    double z[5];
    t5_fun(x,y,z,5);
    for(int i=0;i<5;i++){
        printf("%lf ",z[i]);
    }
    printf("\n");
    return 0;
}
