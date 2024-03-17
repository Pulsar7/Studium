.section .rodata
text:
    .asciz "'A' - 0454 + 0x12345678 = %d\n"

.section .text
.global main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp

    ### a)

    # using 'movq' in order to be sure the register is empty apart from our values
    movq $'A', %rax
    movq $300, %rbx # 0454 = 300 (dec) 
    movq $0x12345678, %rcx

    subw %bx, %ax # 65 - 300
    movswl %ax, %eax # convert to 'signed int'
    addl %ecx, %eax # 0x12345678 + (65 - 300)(dec)


    ### b) 

    cltq # result is positive

    ### c)

    movq $text, %rdi
    movq %rax, %rsi # for 'printf' the result has to be in the %rsi
    movl %eax, %esi
    movq $0, %rax # disable float-register
    call printf

    movq $0, %rax
    popq %rbp
    ret
