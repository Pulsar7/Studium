.section .rodata
newline:
.asciz "\n"
.section .text
.type _start, @function
.globl _start

_start:
    pushq %rbp
    movq %rsp, %rbp

    ### a) 

    subq $8, %rsp # Decreased Stack-Pointer for new entry
    movq $3, (%rsp) # Edited value of %rsp

    ### b) 

    addq $4, (%rsp)
    addq $48, (%rsp) # convert from 7 (dec) to '7' (char)

    # SYS_WRITE-Command
    movq $1, %rax # write-command
    movq $1, %rdi # parameter 1
    movq %rsp, %rsi # parameter 2
    movq $1, %rdx # parameter 3
    syscall # execute
    #

    # SYS_WRITE-Command
    movq $1, %rax # write-command
    movq $1, %rdi # parameter 1
    movq $newline, %rsi # parameter 2 -> newline-character
    movq $1, %rdx # parameter 3
    syscall # execute
    #

    ### c) 

    addq $8, %rsp

    ### 
    movq $60, %rax
    xorq %rdi, %rdi
    popq %rbp
    syscall
