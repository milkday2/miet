.data
fmt: .string "%d"

.text
.globl main
main:
pushq %rbp
movq %rsp,%rbp

subq $4,%rsp
andq $-16,%rsp

movl $10, %ecx
imull $3,%ecx,%ecx

leaq fmt(%rip),%rdi
movl %ecx,%esi
xor %eax,%eax
call printf


movq %rbp,%rsp
popq %rbp
xor %eax,%eax
ret
