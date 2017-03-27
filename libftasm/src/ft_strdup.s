global _ft_strdup
extern _ft_strlen
extern _malloc

section .text
_ft_strdup:
	push rbp
	mov rbp, rsp
	mov rax, rdi
	test rdi, rdi
	jz error
	sub rsp, 0x20

	mov qword[rsp], rdi
	mov qword[rsp + 0x8], 0
	mov qword[rsp + 0x10], 0
	call _ft_strlen
	
	mov qword[rsp + 0x10], rax

alloc:
	mov rdi, rax
	inc rdi
	call _malloc
	test rax, rax
	jz error

duplicate:
	mov qword[rsp + 0x8], rax
	mov rdi, rax
	mov rsi, qword[rsp]
	mov rcx, qword[rsp + 0x10]

	cld
	rep movsb
	inc rdi
	mov byte[rdi], 0
	jmp end

error:
	mov rax, 0

end:
	leave
	ret
