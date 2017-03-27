global _ft_strcpy

section .text
_ft_strcpy:
	mov rax, rdi
	test rdi, rdi
	jz end
	test rsi, rsi
	jz end

	mov r8, rdi
	mov r9, rsi
	xor rcx, rcx

strcpy:
	cmp byte[rsi + rcx], 0x0
	mov al, byte[rsi + rcx]
	mov byte[rdi + rcx], al
	je pointer
	inc rcx
	jmp strcpy

pointer:
	mov rdi, r8
	mov rsi, r9
	mov rax, rdi

end:
	ret
