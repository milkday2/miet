.data
    scanfmt: .string "%hd %hd"
    printfmt: .string "%hd  %hd\n"

.text
.globl main

main:
    pushq %rbp
    movq %rsp, %rbp

    subq $4,%rsp
    andq $-16,%rsp

    leaq scanfmt(%rip),%rdi
    leaq -2(%rbp),%rsi #x
    leaq -4(%rbp),%rdx #y
    xor %eax,%eax
    call scanf

    leaq printfmt(%rip),%rdi
    movswl -2(%rbp),%esi
    movswl -4(%rbp),%edx
    xor %eax,%eax
    call printf


    movq %rbp,%rsp
    popq %rbp
    xor %eax, %eax
    ret
