.data
    scanfmt: .string "%lld %lld"
    printfmt: .string "%lld  %lld\n"

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
    xor %eax,%eax
    call scanf

    leaq printfmt(%rip),%rdi
    movq -8(%rbp),%rsi
    movq -16(%rbp),%rdx
    xor %eax,%eax
    call printf


    movq %rbp,%rsp
    popq %rbp
    xor %eax, %eax
    ret


