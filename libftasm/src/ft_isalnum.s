global _ft_isalnum

section .text
_ft_isalnum:
	cmp rdi, 0x30
	jl false
	cmp rdi, 0x7a
	jg false
	cmp rdi, 0x39
	jle true
	cmp rdi, 0x61
	jge true
	cmp rdi, 0x5a
	jg false
	cmp rdi, 0x41
	jl false

	jmp true

false:
	mov rax, 0x00
	jmp end

true:
	mov rax, 0x01
	jmp end
	
end:
	ret
