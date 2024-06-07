[BITS 64]

section .text
    global strncmp

strncmp:
    push    rbp
    mov     rbp, rsp
    cmp     rdx, 0
    je      exit_null
    mov     rcx, 0

loop:
    cmp    rdx, rcx
    je     exit
    mov    r10b, [rdi]
    mov    r11b, [rsi]
    cmp    r11b, 0
    je     exit
    cmp    r10b, r11b
    jne    exit
    inc    rdi
    inc    rsi
    inc    rcx
    jmp    loop

exit:
    sub    r10b, r11b
    movsx  rax, r10b
    mov    rsp, rbp
    pop    rbp
    ret

exit_null:
    mov    rax, 0
    mov    rsp, rbp
    pop    rbp
    ret
