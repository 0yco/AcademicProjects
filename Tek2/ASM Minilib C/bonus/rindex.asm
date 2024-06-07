[BITS 64]

section .text
    global rindex

rindex:
    push   rbp
    mov    rbp, rsp
    mov    rax, 0
    cmp    sil, 0
    je     exit_zero_loop

loop:
    cmp    [rdi], BYTE 0
    je     exit
    cmp    [rdi], BYTE sil
    je     found
    inc    rdi
    jmp    loop

found:
    mov    rax, rdi
    inc    rdi
    jmp    loop

exit_zero_loop:
    cmp    [rdi], BYTE 0
    je     exit_zero
    inc    rdi
    jmp    exit_zero_loop

exit_zero:
    mov    rax, rdi

exit:
    mov    rsp, rbp
    pop    rbp
    ret
