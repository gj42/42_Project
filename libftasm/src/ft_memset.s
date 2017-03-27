global _ft_memset

section .text
_ft_memset:
	mov r10, rdi
	test rdi, rdi
	jz end
	mov rcx, rdx

memset:
	test rcx, rcx
	jz end
	mov al, sil
	cld
	rep stosb

end:
	mov rax, r10
	ret
