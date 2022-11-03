BITS 64

global asm_strcasecmp
; rdi = string1
; rsi = string2

asm_strcasecmp:
    push rcx
    push rdx
    xor rcx, rcx
    xor rax, rax
    xor rdx, rdx
compare:
    mov al, [rdi + rcx]
    mov dl, [rsi + rcx]
    cmp al, byte 0
    jz first_ends
    cmp dl, byte 0
    jz second_ends
    cmp al, dl
    jl less
    jg greater
goto_next:
    inc rcx
    jmp compare

greater:
    cmp al, 'a'
    jl return_greater
    cmp al, 'z'
    jg return_greater
    sub al, 32
    jmp second_try

less:
    cmp dl, 'a'
    jl return_less
    cmp dl, 'z'
    jg return_less
    sub dl, 32
    jmp second_try

second_try:
    cmp al, dl
    jl return_greater
    jg return_less
    jmp goto_next


first_ends:
    cmp dl, byte 0
    jz return_matched
    jmp return_less

second_ends:
    jmp return_greater

return_matched:
    xor rax, rax
    jmp quit

return_greater:
    xor rax, rax
    inc rax
    jmp quit

return_less:
    xor rax, rax
    dec rax
    jmp quit

quit:
    pop rdx
    pop rcx
    ret
