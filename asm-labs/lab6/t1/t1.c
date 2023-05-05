#include <stdio.h>

int t1_fun(int x,int y);

int t1_fun_C(int x,int y){
    return 19+x+2*y;
}

int main(void){
    int x;
    int y;
    scanf("%d %d",&x,&y);
    printf("asm:%d\nC:%d\n",t1_fun(x, y),t1_fun_C(x, y));
    return 0;
}
