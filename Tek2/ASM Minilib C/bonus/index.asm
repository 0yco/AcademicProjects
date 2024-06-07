[BITS 64]

section .text
    global index

index:
    push   rbp
    mov    rbp, rsp

loop:
    cmp    [rdi], BYTE sil
    je     found
    cmp    [rdi], BYTE 0
    je     not_found
    inc    rdi
    jmp    loop

found:
    mov    rax, rdi
    mov    rsp, rbp
    pop    rbp
    ret

not_found:
    mov    rax, 0
    mov    rsp, rbp
    pop    rbp
    ret
