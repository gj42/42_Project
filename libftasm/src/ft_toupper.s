global _ft_toupper

section .text
_ft_toupper:
	mov rax, rdi
	cmp rdi, 0x61
	jl end
	cmp rdi, 0x7a
	jg end

	sub rax, 0x20

end:
	ret
