.section .rodata
name:
	.asciz "Benedikt Fichtner\n"
matrikelnummer:
	.asciz "3390948\n"

.section .text
.type _start, @function
.global _start

_start:
	pushq %rbp
	movq %rsp, %rbp

	#call write for name
	movq $1, %rax
	movq $1, %rdi
	movq $name, %rsi
	movq $18, %rdx
	syscall

	#call write for matrikelnummer
        movq $1, %rax
        movq $1, %rdi
	movq $matrikelnummer, %rsi
        movq $8, %rdx
        syscall

	#exit
	movq $60, %rax
	xorq %rdi, %rdi

	popq %rbp
	syscall
