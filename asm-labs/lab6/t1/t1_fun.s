.text
.globl t1_fun

# int t1_fun(int x,int y);
t1_fun:
    imull $2,%esi,%eax
    addl $19,%edi
    addl %edi,%eax
    ret
