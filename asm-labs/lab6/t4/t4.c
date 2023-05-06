#include <stdio.h>

double t4_fun(double x,double y);

int main(void){
    double x;
    double y;
    scanf("%lf %lf",&x,&y);
    printf("x - y = %lf\n",t4_fun(x, y));
    return 0;
}
