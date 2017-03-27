global _ft_isupper

section .text
_ft_isupper:
	cmp rdi, 0x41
	jl false
	cmp rdi, 0x5a
	jg false

true:
	mov rax, 0x01
	jmp end

false:
	mov rax, 0x00
	jmp end

end:
	ret
