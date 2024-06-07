[BITS 64]

section .text
    global strpbrk

strpbrk:
    push   rbp
    mov    rbp, rsp

loop_new_chr:
    mov    rcx, 0
    mov    r10b, [rdi]
    cmp    r10b, BYTE 0
    je     not_found

loop_search_in:
    cmp    [rsi + rcx], BYTE r10b
    je     found
    cmp    [rsi + rcx], BYTE 0
    je     continue
    inc    rcx
    jmp    loop_search_in

continue:
    inc    rdi
    jmp    loop_new_chr

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
