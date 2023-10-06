global ft_read
extern __errno_location

section .text
ft_read:
    mov rax, 0
    syscall
    test rax, rax
    js .handle_error
    ret
.handle_error:
    mov rdi, rax
	call __errno_location
	neg rdi
	mov [rax], rdi
	mov rax, -1
	ret