[BITS 64]

section .text
    global memcpy

memcpy:
    push    rbp
    mov     rbp, rsp
    mov     rcx, 0

loop:
    cmp    rdx, rcx
    je     exit
    mov    r10b, [rsi + rcx]
    mov    [rdi + rcx], r10b
    inc    rcx
    jmp    loop

exit:
    mov    rax, rdi
    mov    rsp, rbp
    pop    rbp
    ret
