global _ft_tolower

section .text
_ft_tolower:
	mov rax, rdi
	cmp	rdi, 0x41
	jl end
	cmp rdi, 0x5a
	jg end

	add rax, 0x20

end:
	ret
