.section .rodata
newline:
.asciz "\n"
.section .text
.type _start, @function
.globl _start

_start:
    pushq %rbp
    movq %rsp, %rbp




    movq $60, %rax
    xorq %rdi, %rdi
    popq %rbp
    syscall
