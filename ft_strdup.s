global ft_strdup
extern ft_strlen
extern malloc
extern ft_strcpy

section .text
ft_strdup:
    push rdi				; push source to stack
    call ft_strlen
    inc rax       			; len + 1
    mov rdi, rax
    call malloc
    test rax, rax
    jz .fail_malloc
    pop rsi
    mov rdi, rax
    call ft_strcpy
    ret

.fail_malloc:
    xor rax, rax
    ret

