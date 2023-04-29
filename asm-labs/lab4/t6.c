#include <stddef.h>
#include <stdio.h>

int main(void){
    short x,y,z,w; 
    scanf("%hd",&x);
    scanf("%hd",&y);
    short tmpy;
    __asm__("movw %[Y],%[tmpy]\n"
            "subw $2, %[tmpy]\n"
            "xor %%dx,%%dx\n"
            "movw %[X],%%ax\n"
            "divw %[tmpy]\n"
            "movw %%ax,%[Z]\n"
            "movw %%dx,%[W]"
            :[Z]"=r"(z),[W]"=r"(w),[tmpy]"=&r"(tmpy)
            :[Y]"m"(y),[X]"m"(x):"dx","ax","cx");
    printf("%d\n%d\n",z,w);
    return 0;
}


