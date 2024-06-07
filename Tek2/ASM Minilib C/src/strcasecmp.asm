[BITS 64]

section .text
    global strcasecmp

strcasecmp:
    push    rbp
    mov     rbp, rsp

to_lowercase:
    mov    r10b, [rdi]
    mov    r11b, [rsi]

rdi_to_lower:
    cmp    r10b, 0x41
    jl     rsi_to_lower
    cmp    r10b, 0x5A
    jg     rsi_to_lower
    add    r10b, 0x20

rsi_to_lower:
    cmp    r11b, 0x41
    jl     loop
    cmp    r11b, 0x5A
    jg     loop
    add    r11b, 0x20

loop:
    cmp    r10b, 0
    je     exit
    cmp    r11b, 0
    je     exit
    cmp    r10b, r11b
    jne    exit
    inc    rdi
    inc    rsi
    jmp    to_lowercase

exit:
    sub    r10b, r11b
    movsx  rax, r10b
    mov    rsp, rbp
    pop    rbp
    ret
