.section .rodata

result_text:
    .asciz "x=%d y=%d z=%d » The result is: %d «\n"

add_text:
    .asciz "Added %d + %d\n"

sub_text:
    .asciz "Subtracted %d - %d\n"

.section .data

.section .text

.global add_func
.type add_func, @function

add_func:
    pushq %rdi
    pushq %rsi
    pushq %rdx

    movq %rdx, %r14
    addq %rsi, %rdx
    movq %rdx, %rax
    pushq %rax
    # printf
    movq $add_text, %rdi
    movq %r14, %rdx
    call printf

    popq %rax
    popq %rdx
    popq %rsi
    popq %rdi
    ret

.global sub_func
.type sub_func, @function

sub_func:
    pushq %rdi
    pushq %rsi
    pushq %rdx

    movq %rdx, %r14
    subq %rsi, %rdx
    movq %rdx, %rax
    pushq %rax
    # printf
    movq $add_text, %rdi
    movq %r14, %rdx
    call printf

    popq %rax
    popq %rdx
    popq %rsi
    popq %rdi
    ret

.global calc_func
.type calc_func, @function

calc_func:
    cmpq %rdi, %rsi
    jge .L1 # y (%rsi) >= x (%rdi)?
    jmp .L2 
    ret

.L1:
    call add_func
    jmp .RESULT

.L2:
    call sub_func

.RESULT:
    # printf
    movq %rsp, %r14
    andq $0xFFFFFFFFFFFFFFF0, %rsp   # align stack

    movq %rax, %r8
    movq %rdx, %rcx
    movq %rsi, %rdx
    movq %rdi, %rsi
    movq $result_text, %rdi
    call printf
    movq %r14, %rsp
    ret

.global main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp

    movq $2, %rdi   # x
    movq $1, %rsi   # y
    movq $3, %rdx   # z
    call calc_func
       

    # exit
    popq %rbp
    movq $0, %rax
    ret
