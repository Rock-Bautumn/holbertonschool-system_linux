BITS 64

global asm_putc
; size_t asm_putc(int c);
; rdi = int c

asm_putc:
    push rdi
    push rsi
    push rdx
    sub rsp, 8
    mov rax, 1
    mov [rsp+8], rdi
    lea rsi, [rsp+8]
    mov rdi, 1
    mov rdx, 1
    syscall
    mov rax, 1
    add rsp, 8
    pop rdx
    pop rsi
    pop rdi
    ret
