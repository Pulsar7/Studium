.section .rodata

.section .data

intarr:
    .int 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

.section .text

.global main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp

    leaq intarr, %rdi           # start-address of array
    movq $0, %rsi               # index = 0
    movl (%rdi, %rsi, 4), %r9d   # load value at intarr[index]

    # Exit
    movq $0, %rax
    popq %rbp
    ret
