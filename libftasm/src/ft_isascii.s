global _ft_isascii

section .text
_ft_isascii:
	cmp rdi, 0x00
	jl false
	cmp rdi, 0x7f
	jg false

true:
	mov rax, 0x01
	jmp end

false:
	mov rax, 0x00
	jmp end

end:
	ret
