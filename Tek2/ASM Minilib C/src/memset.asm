[BITS 64]

section .text
    global memset

memset:
    push    rbp
    mov     rbp, rsp
    mov     rcx, 0

loop:
    cmp    rdx, rcx
    je     exit
    mov    [rdi + rcx], BYTE sil
    inc    rcx
    jmp    loop

exit:
    mov    rax, rdi
    mov    rsp, rbp
    pop    rbp
    ret
