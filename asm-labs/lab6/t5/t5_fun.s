
.text
.globl t5_fun

# void t5_fun(double* x,double* y,double* z,size_t size);
# x-> rdi, y -> rsi,z -> rdx, size -> rcx
t5_fun:
    movq $0,%rax
begin_loop:
    movsd (%rdi,%rax,8),%xmm0
    subsd (%rsi,%rax,8),%xmm0
    movsd %xmm0,(%rdx,%rax,8)

    inc %rax
    cmpq %rcx,%rax
    jb begin_loop

    ret
    
    
    
