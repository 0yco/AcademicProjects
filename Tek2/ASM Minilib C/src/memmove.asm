[BITS 64]

section .text
    global memmove

memmove:
    push    rbp
    mov     rbp, rsp
    mov     rcx, 0
    cmp     rdi, rsi
    jg      loop_reverse

loop:
    cmp    rdx, rcx
    je     exit
    mov    r10b, [rsi + rcx]
    mov    [rdi + rcx], r10b
    inc    rcx
    jmp    loop

loop_reverse:
    cmp    rdx, 0
    je     exit
    mov    r10b, [rsi + rdx]
    mov    [rdi + rdx], r10b
    dec    rdx
    jmp    loop_reverse

exit:
    mov    rax, rdi
    mov    rsp, rbp
    pop    rbp
    ret
