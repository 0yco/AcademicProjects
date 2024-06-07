[BITS 64]

section .text
    global strtok

strtok:
    push   rbp
    mov    rbp, rsp
    mov    rcx, 0
    cmp    [rsi], BYTE 0
    je     exit

loop:
    mov    r10b, [rdi + rcx]
    cmp    r10b, [rsi]
    je     init_compare
    cmp    [rdi + rcx], BYTE 0
    je     not_found
    inc    rcx
    jmp    loop

init_compare:
    mov    rdx, rcx
    mov    rcx, 0

compare:
    mov    r11b, [rsi + rcx]
    cmp    r11b, 0
    je     found
    cmp    [rdi + rdx], r11b
    jne    continue
    cmp    [rdi + rdx], BYTE 0
    je     not_found
    inc    rcx
    inc    rdx
    jmp    compare

continue:
    sub    rdx, rcx
    mov    rcx, rdx
    inc    rcx
    jmp    loop

found:
    sub    rdx, 1
    mov    [rdi + rdx], BYTE 0

exit:
    mov    rax, rdi
    mov    rsp, rbp
    pop    rbp
    ret

not_found:
    mov    rax, 0
    mov    rsp, rbp
    pop    rbp
    ret
