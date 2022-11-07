BITS 64

global div_10
global main

; rcx - int_max repeat
; rax the n to get digits of
; r8 - the digits
; rdx - required for div

main:
div_10:
    push rcx
    push rdx
    push r8
    xor rdx, rdx
    xor rcx, rcx
start:
    mov rax, 1234567
    xor r8, r8
div_it:
    movsx dx, 10 
    div ax, dx
    inc r8
    cmp rax, 0
    jnz div_it
    mov rax, r8
    cmp rcx, 2147483647
    jl start
end:
    pop r8
    pop rdx
    pop rcx
    ret
