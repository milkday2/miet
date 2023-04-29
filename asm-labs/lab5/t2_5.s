.data
    scanfmt: .string "%lf %lf"
    printfmt: .string "%lf  %lf\n"

.text
.globl main

main:
    pushq %rbp
    movq %rsp, %rbp

    subq $16,%rsp
    andq $-16,%rsp

    leaq scanfmt(%rip),%rdi
    leaq -8(%rbp),%rsi #x
    leaq -16(%rbp),%rdx #y
    movb $0,%al
    call scanf

    leaq printfmt(%rip),%rdi
    movsd -8(%rbp),%xmm0
    movsd -16(%rbp),%xmm1
    movb $2,%al
    call printf


    movq %rbp,%rsp
    popq %rbp
    xor %eax, %eax
    ret




