%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

global _ft_putchar_fd

section .text
_ft_putchar_fd:
	push rbp
	mov rbp, rsp

putcharfd:
	push rdi
	mov rdi, rsi
	lea rsi, [rel rsp]
	xor rdx, rdx
	inc rdx
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi

end:
	mov al, dil
	leave
	ret
