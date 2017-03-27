%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

global _ft_putchar

section .text
_ft_putchar:
	push rbp
	mov rbp, rsp

putchar:
	push rdi
	lea rsi, [rel rsp]
	mov rdi, STDOUT
	xor rdx, rdx
	inc rdx
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi

end:
	mov al, dil
	leave
	ret
