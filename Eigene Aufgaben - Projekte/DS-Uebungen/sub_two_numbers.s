.section .rodata

.section .data

.section .text

.global main
.type main, @function

main:
    pushq %rbp
	movq %rsp, %rbp

    movl $1, %eax
    movl $2, %ebx
    subl %ebx, %eax

    # exit
    movq $0, %rax
	popq %rbp
    ret
