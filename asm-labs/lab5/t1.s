.data
    message: .string "Konovalov A.,PIN-23"

.text
.globl main

main:
    pushq %rbp
    movq %rsp,%rbp

    leaq message(%rip),%rdi
    call puts

    movq %rbp,%rsp
    popq %rbp
    xor %eax, %eax
    ret
