global _ft_bzero

section .text
_ft_bzero:
	xor r8, r8

while:
	cmp r8, rsi
	jge	end
	cmp rdi, 0
	je 	end
	mov	byte[rdi + r8], 0
	inc	r8
	jmp while

end:
	ret
