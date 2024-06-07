[BITS 64]

section .text
    global strcspn

strcspn:
    push   rbp
    mov    rbp, rsp
    mov    rax, 0

loop_new_chr:
    mov    rcx, 0
    mov    r10b, [rdi + rax]
    cmp    r10b, BYTE 0
    je     end

loop_search_in:
    cmp    [rsi + rcx], r10b
    je     end
    cmp    [rsi + rcx], BYTE 0
    je     continue
    inc    rcx
    jmp    loop_search_in

continue:
    inc    rax
    jmp    loop_new_chr

end:
    mov    rsp, rbp
    pop    rbp
    ret
