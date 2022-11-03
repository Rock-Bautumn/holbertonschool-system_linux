BITS 64

global	asm_strstr
	; char *strchr(char *string, char *string2);
    ; rdi = char *string
    ; rsi = char *string2

asm_strstr:
    push r8
    push r9
    push r10
    push rcx
    push rdx

search_start:
    movzx rax, BYTE [rdi]
    cmp rax, BYTE 0
    jz no_match
    movzx rdx, BYTE [rsi]
    cmp rdx, 0
    jz found_start
    cmp rax, rdx
    je find_match

    inc rdi
    jmp search_start

find_match:
    mov r8, rsi
    mov r9, rdi
match_string:
    cmp [r8 + 1], BYTE 0
    jz match_found
    cmp [r8], BYTE 0
    jz match_found
    inc r8
    inc r9
    movzx r10, BYTE [r8]
    movzx rcx, BYTE [r9]
    cmp r10, rcx
    je match_string
    jmp dead_no_match

no_match:
    movzx rdx, BYTE [rsi]
    cmp rdx, 0
    jz found_start
dead_no_match:
    xor rax, rax
    jmp cleanup

found_start:
    cmp rax, 0
    jz match_found
    mov rax, rdi
    jmp cleanup

match_found:
    mov rax, rdi
    jmp cleanup

cleanup:
    pop rdx
    pop rcx
    pop r10
    pop r9
    pop r8
    ret
