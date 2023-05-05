
.text
.globl t3_fun

# int* t3_fun(int x0,size_t N);
# x0 -> edi, N -> rsi
t3_fun:
pushq %rbx
pushq %rbp
movq %rsp,%rbp

subq $12,%rsp
andq $-16,%rsp

movl %edi,-4(%rbp)
movq %rsi,-12(%rbp)
imulq $4,%rsi,%rdi
call malloc
movq %rax,%rbx # array pointer -> rbx
movl -4(%rbp),%edi
movq -12(%rbp),%rsi

movl %edi,(%rbx) # x0 -> arr[0]

movq $1,%rcx # counter
begin_loop:
test $1,%edi
jz even
jmp odd

even:
movl %edi,%eax
shrl $31,%eax
addl %eax,%edi
sarl $1,%edi

movl %edi,(%rbx,%rcx,4)

inc %rcx
cmpq %rsi,%rcx
jb begin_loop
jmp end_loop
odd:
imull $3,%edi,%edi
inc %edi

movl %edi,(%rbx,%rcx,4)

inc %rcx
cmpq %rsi,%rcx
jb begin_loop

end_loop:

movq %rbx,%rax

movq %rbp,%rsp
popq %rbp
popq %rbx
ret
