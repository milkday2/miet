#include <stddef.h>
#include <stdio.h>

int main(void){
    int x,y,z,w; 
    scanf("%d",&x);
    scanf("%d",&y);
    __asm__("movl (%[pY]),%%ecx\n"
            "subl $2,%%ecx\n"
            "xor %%edx,%%edx\n"
            "movl (%[pX]),%%eax\n"
            "divl %%ecx\n"
            "movl %%eax,%[Z]\n"
            "movl %%edx,%[W]"
            :[Z]"=r"(z),[W]"=r"(w)
            :[pY]"r"(&y),[pX]"r"(&x)
            :"edx","eax","ecx");
    printf("%d\n%d\n",z,w);
    return 0;
}
