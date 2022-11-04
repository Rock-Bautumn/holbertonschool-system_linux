BITS 64

global asm_strspn

; size_t asm_strspn(const char *s, const char *accept);

; Count how many successive characters in s are found in accept, from the beginning

; rdi = char *s
; rsi = char *accept
; rcx = successful iterations, return value
; rdx/dl = s char in question
; rbx/bl = accept char in question
; r9 = accept char address position

asm_strspn:
    push rcx
    push rdx
    push rbx
    push r9
    xor rdx, rdx
    xor rcx, rcx
    xor rbx, rbx

zcompare_char:
    mov dl, [rdi + rcx]
    cmp dl, 0
    jz quit
    xor r9, r9
zsearch_char:
    mov bl, [rsi + r9]
    cmp bl, 0
    jz quit
    cmp dl, bl
    jne znew_search
    inc rcx
    jmp zcompare_char

znew_search:
    inc r9
    jmp zsearch_char

quit:
    mov rax, rcx
    pop r9
    pop rbx
    pop rdx
    pop rcx
    ret
