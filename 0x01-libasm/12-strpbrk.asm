BITS 64

global asm_strpbrk

; Find the first occurrence of a character from accept in string1

; rdi = char *str
; rsi = char *accept
; rcx = successful iterations, used in return value
; rdx/dl = s char in question
; rbx/bl = accept char in question
; r9 = accept char address position

asm_strpbrk:
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
    jz no_match
    xor r9, r9
zsearch_char:
    mov bl, [rsi + r9]
    cmp bl, 0
    jz znew_compare
    cmp dl, bl
    je quit
    inc r9
    jmp zsearch_char

znew_compare:
    inc rcx
    jmp zcompare_char

no_match:
    xor rax, rax
    jmp quit2

quit:
    mov rax, rdi
    add rax, rcx
quit2:
    pop r9
    pop rbx
    pop rdx
    pop rcx
    ret
