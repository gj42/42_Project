global _ft_strnew
extern _ft_memalloc

section .text
_ft_strnew:
	push rbp
	mov rbp, rsp
	sub rsp, 0x10

	mov [rbp - 8], rdi
	inc rdi
	call _ft_memalloc
	mov rdi, [rbp - 8]
	test rax, rax
	jz ret_null

end:
	leave
	ret

ret_null:
	xor rax, rax
	jmp end	
