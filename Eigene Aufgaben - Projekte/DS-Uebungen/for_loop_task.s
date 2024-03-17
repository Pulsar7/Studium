.section .rodata                            # read-only-data

    result_text:
        .asciz "Result = %ld\n"


.section .bss                               # not initialized values


.section .data

    .align 16
    arrL:
        .quad 200, 55, 13, -17, 24


.section .text

.global main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp

    # FOR-LOOP
    movl $0, %r8d                           # int i = 0;
    movl $5, %r9d                           # 5 elements (max_value)
    leaq arrL, %r10                         # load start-address of array in %r10
    movq $0, %r11                           # Result of addition (result_value)
    jp for_test

    for_body:
        movq (%r10, %r8, 8), %r12           # arrL[i]
        addq %r12, %r11                     # result_value += arrL[i];
        addl $1, %r8d                       # i++;

    for_test:
        cmpl %r8d, %r9d
        jne for_body                        # i != max_value

    # PRINTF
    # movq $result_text, %rdi               # 1. Argument: string
    # or:
    leaq result_text, %rdi
    movq %r11, %rsi                         # 2. Argument: result_value
    call printf

    # exit
    popq %rbp
    movq $0, %rax
    ret

