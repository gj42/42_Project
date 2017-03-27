global	_ft_memalloc
extern	_malloc
extern	_ft_bzero

section .text
_ft_memalloc:
	push rbp
	mov rsp, rbp
	test rdi, rdi
	jz retnull

	push rdi
	call _malloc
	test rax, rax
	jz end
	
	pop rdi
	mov r9, rax
	mov rsi, rdi
	mov rdi, rax

	call _ft_bzero

	mov rax, r9

end:
	leave
	ret	

retnull:
	xor rax, rax
	jmp end
