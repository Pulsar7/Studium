.section .rodata


.section .text
.global main
.type main, @function

main:
    pushq %rbp
	movq %rsp, %rbp

    movl $1, %eax
    movl $2, %ebx
    movq $0, %r8    # clear the %r8
    addl %eax, %ebx

    # Exit
    movq $0, %rax
	popq %rbp
    ret
