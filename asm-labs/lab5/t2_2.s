.data
    scanfmt: .string "%d %d"
    printfmt: .string "%d  %d\n"

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
    xor %eax,%eax
    call scanf

    leaq printfmt(%rip),%rdi
    movl -4(%rbp),%esi
    movl -8(%rbp),%edx
    xor %eax,%eax
    call printf


    movq %rbp,%rsp
    popq %rbp
    xor %eax, %eax
    ret

