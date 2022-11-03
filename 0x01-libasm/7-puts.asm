BITS 64

global asm_puts
extern asm_strlen
; write = rax 1, rdi fd, rsi ADDR, rdx size
asm_puts:
    push rdi
    push rsi
    push rdx
    mov rsi, rdi
    call asm_strlen
    mov rdx, rax
    mov rdi, 1
    mov rax, 1
    syscall
    mov rax, rdx
    pop rdx
    pop rsi
    pop rdi
    ret
