BITS 64

global asm_strcasecmp
; rdi = string1
; rsi = string2

asm_strcasecmp:
    push rbx
    push rcx
    push rdx
    xor rcx, rcx
    xor rax, rax
    xor rdx, rdx
    xor rbx, rbx
compare:
    mov bl, [rdi + rcx]
    mov dl, [rsi + rcx]

save_difference:
    mov al, bl
    sub al, dl
    movsx rax, al

    cmp bl, byte 0
    jz first_ends
    cmp dl, byte 0
    jz second_ends
    cmp bl, dl
    jl less
    jg greater
goto_next:
    inc rcx
    jmp compare

greater:
    cmp bl, 'a'
    jl return_greater
    cmp bl, 'z'
    jg return_greater
    sub bl, 32
    jmp second_try

less:
    cmp dl, 'a'
    jl return_less
    cmp dl, 'z'
    jg return_less
    sub dl, 32
    jmp second_try

second_try:
    cmp bl, dl
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
    ; sub bl, dl
    ; movzx rax, bl
    jmp quit

return_less:
    ; sub dl, bl
    ; neg dl
    ; movsx rax, dl
    jmp quit

quit:
    pop rdx
    pop rcx
    pop rbx
    ret
