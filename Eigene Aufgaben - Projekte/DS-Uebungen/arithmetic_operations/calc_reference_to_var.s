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

    movq %rdx, %r14                     # save %rdx in %r14 (Callee saved)
    addq %rsi, %rdx                     # y + z
    movq %rdx, %rax                     # Move result of addition in %rax
    pushq %rax

    # printf
    movq $add_text, %rdi
    movq %rsi, %rdx
    movq %r14, %rsi
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

    movq %rdx, %r14                     # Save %rdx in %r14 (Callee saved)
    subq %rsi, %rdx                     # z - y
    movq %rdx, %rax                     # Move result of subtraction in %rax
    pushq %rax
    
    # printf
    movq $sub_text, %rdi
    movq %rsi, %rdx
    movq %r14, %rsi
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
    jge .L1                             # y (%rsi) >= x (%rdi)?
    jmp .L2                             # y (%rsi) < x (%rdi)?
    ret

.L1:
    call add_func
    jmp .RESULT

.L2:
    call sub_func

.RESULT:
    # printf
    movq %rsp, %r14                     # save %rsp in %r14 (Callee saved)
    andq $0xFFFFFFFFFFFFFFF0, %rsp      # align stack to 16 Bytes

    movq %rax, %r8                      # 5. (Result of calculation)
    movq %rdx, %rcx                     # 4. (z)
    movq %rsi, %rdx                     # 3. (y)
    movq %rdi, %rsi                     # 2. (x)
    movq $result_text, %rdi             # 1. (printout-string)
    call printf

    movq %r14, %rsp
    ret

.global main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp

    subq $24, %rsp                      # allocate 24-Bytes on stack
    movq $1, 16(%rsp)                   # x
    movq $2, 8(%rsp)                    # y
    movq $3, (%rsp)                     # z
    
    # write effective addr to registers as func-params
    leaq 16(%rsp), %rdi              
    leaq 8(%rsp), %rsi                
    leaq (%rsp), %rcx
    call calc_func
    

    # exit
    addq $24, %rsp                      # free space on stack (Deallocate)
    popq %rbp
    movq $0, %rax
    ret
