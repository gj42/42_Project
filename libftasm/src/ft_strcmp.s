global _ft_strcmp

section .text
_ft_strcmp:
	mov rax, -1
	test rdi, rdi
	jz end
	test rsi, rsi
	jz end

strcmp:
	mov r8, rdi
	mov r9, rsi

	xor rax, rax
	xor rcx, rcx
	xor rbx, rbx

next:
	mov al, byte[rdi + rcx]
	mov bl, byte[rsi + rcx]
	cmp al, 0x0
	je dif
	cmp bl, 0x0
	je dif
	add rcx, 1
	cmp al, bl
	je next

dif:
	sub rax, rbx
	mov rdi, r8
	mov rsi, r9

end:
	ret
