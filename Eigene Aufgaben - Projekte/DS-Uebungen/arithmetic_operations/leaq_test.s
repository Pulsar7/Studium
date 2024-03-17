.section .rodata

.section .bss

.section .data

.section .text

.globl main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp

    movq $1, %rdi
    movq $1, %rsi
    leaq 2(%rdi, %rsi, 2), %rax

    # exit
    popq %rbp
    movq $0, %rax
    ret
