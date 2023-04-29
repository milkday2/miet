#include <stdio.h>


int main(void){
    int x,y,z;
    char overflow;
    scanf("%d",&x);
    scanf("%d",&y);
    printf("(%d) + (%d) =\n",x,y);
    __asm__("addl %[X],%[Y]\n"
            "seto %[OF]\n"
            "movl %[Y],%[Z]\n"
            :[Z]"=r"(z),[OF]"=r"(overflow)
            :[X]"r"(x),[Y]"r"(y)
            :);
    printf("%d %X\n",z,z);
    if(overflow)
        printf("OVERFLOW\n");
    return 0;
}
