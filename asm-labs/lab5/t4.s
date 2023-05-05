.data
scanfmt: .string "%d %d"
printfmt: .string "%d\n"

.text
.globl main

main:
pushq %rbx
pushq %r12
pushq %r13
pushq %rbp
movq %rsp,%rbp

subq $8,%rsp
andq $-16,%rsp

leaq scanfmt(%rip),%rdi
leaq -4(%rbp),%rsi #N
leaq -8(%rbp),%rdx #x0
xor %eax,%eax
call scanf

movl -4(%rbp),%ebx # N -> ebx
movl -8(%rbp),%r13d # x0 -> r13d
movl $2,-8(%rbp) # probably not needed
movl $0,%r12d # r12d - counter
begin_loop:
test $1,%r13d
jz even
jmp odd

even:
movl %r13d,%eax
shrl $31,%eax
addl %eax,%r13d
sarl $1,%r13d

leaq printfmt(%rip),%rdi
movl %r13d,%esi
xor %eax,%eax
call printf

inc %r12d
cmpl %ebx,%r12d
jl begin_loop
jmp end_loop
odd:
imull $3,%r13d,%r13d
inc %r13d

leaq printfmt(%rip),%rdi
movl %r13d,%esi
xor %eax,%eax
call printf

inc %r12d
cmp %ebx,%r12d
jl begin_loop

end_loop:

movq %rbp,%rsp
popq %rbp
popq %r13
popq %r12
popq %rbx
xor %eax,%eax
ret
