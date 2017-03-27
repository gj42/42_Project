%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define	WRITE				4

global	_ft_puts
extern	_ft_strlen

section .data
nl:
	db 0x0a


section .text
_ft_puts:
	push rbp
	mov rbp, rsp
	test rdi, rdi
	jz ret_eof
	mov r10, rdi
	lea rsi, [rel r10]

	push rsi

	call _ft_strlen

	pop rsi

	xor rdi, rdi
	mov rdi, STDOUT
	xor rdx, rdx
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall

new_line:
	xor rdi, rdi
	mov rdi, STDOUT
	lea rsi, [rel nl]
	xor rdx, rdx
	mov rdx, 0x01
	mov rax, MACH_SYSCALL(WRITE)
	syscall

end:
	mov rsp, rbp
	pop rbp
	ret

ret_eof:
	xor rdi, rdi
	mov rdi, STDOUT
	lea rsi, [rel .msg]
	xor rdx, rdx
	mov rdx, .len
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jmp end


.msg: db "(null)", 0x0a
.len: equ $ - .msg
