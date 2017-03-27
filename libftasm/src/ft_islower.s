global _ft_islower

section .text
_ft_islower:
	cmp	rdi, 0x61
	jl false
	cmp rdi, 0x7a
	jg false

true:
	mov rax, 0x01
	jmp end

false:
	mov rax, 0x00

end:
	ret
