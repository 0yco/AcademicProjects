[BITS 64]

section .text
    global strlen

strlen:
    push   rbp
    mov    rbp, rsp
    mov    rcx, 0

loop:
    cmp    BYTE [rdi + rcx], 0
    je     exit
    inc    rcx
    jmp    loop

exit:
    mov    rax, rcx
    mov    rsp, rbp
    pop    rbp
    ret
