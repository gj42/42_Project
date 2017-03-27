global _ft_isprint

section .text
_ft_isprint:
	cmp	rdi, 0x20
	jl false
	cmp rdi, 0x7e
	jg false

true:
	mov rax, 0x01
	jmp end

false:
	mov rax, 0x00
	
end:
	ret
