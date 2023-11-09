 .section .rodata
text:
    .asciz "'A' - 0454 + 0x12345678 = %d\n"

.section .text
.global main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp

    movq $'A', %rax
    movq $300, %rbx
    movq $0x12345678, %rcx

    subq %rbx, %rax
    addq %rcx, %rax

    movq $text, %rdi
    # movq %rax, %rsi
    movl %eax, %esi
    movq $0, %rax # disable float-register
    call printf

    movq $0, %rax
    popq %rbp
    ret
