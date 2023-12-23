.section .rodata

result_text:
    .asciz "The result is: %d\n"

.section .data

.section .text

.global add_function
.type add_function, @function

add_function:
    addq %rdi, %rsi         # x + y
    movq %rsi, %rax         # result in %rax
    ret

.global main
.type main, @function

main:
    pushq %rbp              # save bottom-stack-pointer
    movq %rsp, %rbp

    movq $1, %rdi
    movq $2, %rsi
    call add_function

    # printf
    movq $result_text, %rdi
    movq %rax, %rsi
    call printf

    # exit
    movq $0, %rax           # clear the %rax
    popq %rbp               # default value in %rbp
    ret
    # WHY A NEWLINE-CHARACTER?! WHY AT THE LAST LINE?!