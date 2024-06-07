[BITS 64]

section .text
    global strstr

strstr:
    push   rbp
    mov    rbp, rsp
    cmp    [rsi], BYTE 0
    je     found

loop:
    mov    r10b, [rdi]
    cmp    r10b, [rsi]
    je     init_compare
    cmp    [rdi], BYTE 0
    je     not_found
    inc    rdi
    jmp    loop

init_compare:
    mov    rcx, 0

compare:
    mov    r11b, [rsi + rcx]
    cmp    r11b, 0
    je     found
    cmp    [rdi + rcx], r11b
    jne    continue
    cmp    [rdi + rcx], BYTE 0
    je     not_found
    inc    rcx
    jmp    compare

continue:
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
