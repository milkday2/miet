
.text
.globl t4_fun

# double t4_fun(double x,double y);
t4_fun:
    subsd %xmm1,%xmm0
    ret
    
