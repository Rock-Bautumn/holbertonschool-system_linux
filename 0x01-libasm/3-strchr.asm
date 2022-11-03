BITS 64

global	asm_strchr
	; char *strchr(const char *string, char chr);
    ; rdi = char *
    ; rsi = char

asm_strchr:
compare:
    ; Can we do this
    movzx rax, BYTE [rdi]
    ; instead of this?
    ;mov al, BYTE [rdi]
    cmp rax, rsi
    je got_char
    cmp rax, BYTE 0
    jz reached_end
    inc rdi
    jmp compare

got_char:
    mov rax, rdi
    ret

reached_end:
    xor rax, rax
    ret
