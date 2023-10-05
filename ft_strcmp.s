global ft_strcmp

section .text
ft_strcmp:
    xor rax, rax
.loop:
    cmp BYTE [rdi + rax], 0
    je .return_diff
    cmp BYTE [rsi + rax], 0
    je .return_diff
    movzx rdx, BYTE [rdi + rax]
    cmp dl, BYTE [rsi + rax]
    jnz .return_diff
    inc rax
    jmp .loop

.return_diff:
    movzx rdx, BYTE [rdi + rax]
    cmp dl, BYTE [rsi + rax]
    jl .little
    je .equal
    ja .above

.little:
    mov rax, -1
    ret
.equal:
    mov rax, 0
    ret
.above:
    mov rax, 1
    ret