.section .rodata

printout_str:
    .asciz "5 divides, but 3 does not divide"

newline_str:
    .asciz "\n"

.section .text
.globl main
.type main, @function
main:
    pushq %rbp
    movq %rsp, %rbp
    pushq $101 # long n = 101 on stack

.L2:
    # Do-While-Body
    decq (%rsp) # n - 1
    movq (%rsp), %rax # Move n in %rax
    cqto # Convert to oct word
    movq $3, %r8
    idivq %r8 # Rest in %rdx
    cmpq $0, %rdx # Rest - 0
    je .L2 # If zero-flag is 1

    # If - Expression
    movq (%rsp), %rax # Move n in %rax
    cqto # Convert to oct word
    movq $5, %r8
    idivq %r8 # Rest in %rdx
    testq %rdx, %rdx # checks if rest is 0
    je .L3 # If zero-flag is 1

    # Expression of do-while-loop
    cmpq $0, (%rsp) # n - 0
    jg .L2 # n > 0

    # Exit programm using gcc
    popq %rax
    movq $0, %rax
    ret

.L3:
    movq $printout_str, %rdi
    call puts
    jmp .L2 # Direct jump !!!
