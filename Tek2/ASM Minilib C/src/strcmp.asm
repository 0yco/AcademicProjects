[BITS 64]

section .text
    global strcmp

strcmp:
    push    rbp
    mov     rbp, rsp

loop:
    mov    r10b, [rdi]
    mov    r11b, [rsi]
    cmp    r10b, 0
    je     exit
    cmp    r11b, 0
    je     exit
    cmp    r10b, r11b
    jne    exit
    inc    rdi
    inc    rsi
    jmp    loop

exit:
    sub    r10b, r11b
    movsx  rax, r10b
    mov    rsp, rbp
    pop    rbp
    ret
