global ft_strlen

section .text
ft_strlen:
	xor rax, rax
.loop:
	cmp BYTE [rdi+rax], 0
	je .rax_equal
	inc rax
	jmp .loop
.rax_equal:
	ret
