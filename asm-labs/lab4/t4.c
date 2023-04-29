#include <stddef.h>
#include <stdio.h>

int main(void){
    int x,y,z,w; 
    scanf("%d",&x);
    scanf("%d",&y);
    __asm__("subl $2, %[Y]\n"
            "xor %%edx,%%edx\n"
            "divl %[Y]\n"
            "movl %%eax,%[Z]\n"
            "movl %%edx,%[W]":[Z]"=r"(z),[W]"=r"(w):[Y]"r"(y),[X]"a"(x):"edx");
    printf("%d\n%d\n",z,w);
    return 0;
}
