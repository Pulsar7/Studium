.section .rodata

result_text:
    .asciz "%d + %d = %d\n"

.section .data

intarr:
    .int 1, 2, 3, 4, 5, 6, 7, 8, 9, 10              # 10 Elements

.section .text

.global add_func
.type add_func, @function

add_func:
    leaq intarr, %rdx                               # load start-addr of array in %rdx
    # intarr[1]
    movq $0, %rcx                                   # index
    movl (%rdx, %rcx, 4), %r14d                     # loads value of element at index 0 of array in %r14d
    # intarr[2]
    addq $1, %rcx                                   # index
    movl (%rdx, %rcx, 4), %r15d                     # loads value of element at index 1 of array in %eax

    movl %r15d, %eax
    addl %r14d, %eax
    cltq                                            # Convert long to quadword (Signed-Extend)

    # printf
    pushq %rax                                      # Save %rax for return

    movq $result_text, %rdi
    movl %r14d, %esi
    movl %r15d, %edx 
    movq %rax, %rcx
    call printf

    popq %rax
    ret

.global main
.type main, @function

main:
    pushq %rbp
    movq %rsp, %rbp

    call add_func

    # Exit
    movq $0, %rax
    popq %rbp
    ret
