.data
    scanfmt: .string "%lf %lf"
    printfmt: .string "%lf^(%lf) = %lf\n"

.text
.globl main

main:
    pushq %rbp
    movq %rsp, %rbp

    subq $24,%rsp
    andq $-16,%rsp

    leaq scanfmt(%rip),%rdi
    leaq -8(%rbp),%rsi #x
    leaq -16(%rbp),%rdx #y
    movb $0,%al
    call scanf

    movsd -8(%rbp),%xmm0
    movsd -16(%rbp),%xmm1
    call pow #result in xmm0

    movsd %xmm0,%xmm2

    leaq printfmt(%rip),%rdi
    movsd -8(%rbp),%xmm0
    movb $3,%al
    call printf


    movq %rbp,%rsp
    popq %rbp
    xor %eax, %eax
    ret





