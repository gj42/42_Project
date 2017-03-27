%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define	WRITE				4

global _ft_putstr
extern _ft_strlen

section .text
_ft_putstr:
	push rbp
	mov rbp, rsp
	test rdi, rdi
	jz end
	mov r10, rdi
	lea rsi, [rel r10]

	push rsi

	call _ft_strlen

	pop rsi

	xor	rdi, rdi
	mov rdi, STDOUT
	xor rdx, rdx
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall

end:
	mov rsp, rbp
	pop rbp
	ret
