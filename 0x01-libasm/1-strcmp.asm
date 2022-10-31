BITS 64

global asm_strcmp

asm_strcmp:
    push rcx

compare:
    cmp [rdi], byte 0
    jz first_ends
    cmp [rsi], byte 0
    jz second_ends
    mov rcx, [rsi]
    cmp [rdi], rcx
    jl less
    jg greater
    inc rdi
    inc rsi
    jmp compare

first_ends:
    cmp [rsi], byte 0
    jz return_matched
    jmp less

second_ends:
    jmp greater

return_matched:
    xor rax, rax
    jmp exit

greater:
    xor rax, rax
    inc rax
    jmp exit

less:
    xor rax, rax
    dec rax
    jmp exit

exit:
    pop rcx
    ret
