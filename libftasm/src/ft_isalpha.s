global _ft_isalpha

section .text
_ft_isalpha:
	cmp rdi, 0x00
	je	false
	cmp rdi, 0x41
	jl	false
	cmp rdi, 0x7a
	jg	false
	cmp rdi, 0x5a
	jle true
	cmp rdi, 0x61
	jge true

	jmp false

true:
	mov rax, 0x01
	jmp end

false:
	mov rax, 0x00
	jmp end

end:
	ret
