BITS 64

global asm_memcpy
; void *asm_memcpy(void *dest, const void *src, size_t n);
; rdi = void *dest
; rsi = void *src
; rdx = size_t n

asm_memcpy:
    push rcx
    push rdx
    mov rax, rdi
move_byte:
    cmp rdx, 0
    jz end
    mov cl, BYTE [rsi]
    mov BYTE [rdi], cl
    inc rdi
    inc rsi
    sub rdx, 1
    jmp move_byte
end:
    pop rdx
    pop rcx
    ret
