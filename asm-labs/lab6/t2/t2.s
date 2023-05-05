
.data
    fmt: .string "return: %d\n"

.text
.globl main

main:
    pushq %rbp
    movq %rsp,%rbp

    // аргументы: edi,esi,edx,ecx,r8d,r9d,stack

    subq $4,%rsp
    andq $-16,%rsp

    movl $7,(%rsp)
    movl $1,%edi
    movl $2,%esi
    movl $3,%edx
    movl $4,%ecx
    movl $5,%r8d
    movl $6,%r9d
    call t2_fun

    leaq fmt(%rip),%rdi
    movl %eax,%esi
    xor %al,%al
    call printf


    movq %rbp,%rsp
    popq %rbp
    xor %eax,%eax
    ret
