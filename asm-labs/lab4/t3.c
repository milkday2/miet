#include <stddef.h>
#include <stdio.h>

int main(void){
    int x,y,z,w; 
    scanf("%d",&x);
    scanf("%d",&y);
    __asm__("movl %[Y],%%ecx\n"
            "subl $2, %%ecx\n"
            "xor %%edx,%%edx\n"
            "movl %[X],%%eax\n"
            "divl %%ecx\n"
            "movl %%eax,%[Z]\n"
            "movl %%edx,%[W]"
            :[Z]"=r"(z),[W]"=r"(w)
            :[Y]"m"(y),[X]"m"(x):"edx","eax","ecx");
    printf("%d\n%d\n",z,w);
    return 0;
}

