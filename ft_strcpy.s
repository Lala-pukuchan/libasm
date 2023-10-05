global ft_strcpy

section .text
ft_strcpy:
	xor rax, rax
.loop:
	cmp BYTE [rsi+rax], 0
	je .rax_equal
	movzx rdx, BYTE [rsi+rax]
	mov BYTE [rdi+rax], dl		; dl is last 8bit of rdx
	inc rax
	jmp .loop
.rax_equal:
	movzx rdx, BYTE [rsi+rax]
	mov BYTE [rdi+rax], dl
	mov rax, rdi
	ret