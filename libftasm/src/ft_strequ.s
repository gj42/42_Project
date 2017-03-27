global _ft_strequ
extern _ft_strcmp

section .text
_ft_strequ:	
	mov rax, -1
	test rdi, rdi
	jz end
	test rsi, rsi
	jz end

strequ:
	call _ft_strcmp

	cmp rax, 0x00
	je equal

notequal:
	mov rax, 0x00
	jmp end

equal:
	mov rax, 0x01

end:
	ret
