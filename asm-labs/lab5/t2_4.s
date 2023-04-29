.data
    scanfmt: .string "%f %f"
    printfmt: .string "%f  %f\n"

.text
.globl main

main:
    pushq %rbp
    movq %rsp, %rbp

    subq $8,%rsp
    andq $-16,%rsp

    leaq scanfmt(%rip),%rdi
    leaq -4(%rbp),%rsi #x
    leaq -8(%rbp),%rdx #y
    movb $0,%al
    call scanf

    leaq printfmt(%rip),%rdi
    cvtss2sd -4(%rbp),%xmm0
    cvtss2sd -8(%rbp),%xmm1
    movb $2,%al
    call printf


    movq %rbp,%rsp
    popq %rbp
    xor %eax, %eax
    ret



