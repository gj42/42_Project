%define MACH_SYSCALL(nb)	0x2000000 | nb
%define	WRITE				4
%define READ				3
%define BUF					0x200

global _ft_cat

section .bss
buffer REST BUF

section .text
_ft_cat:
	push rbp
	mov rbp, rsp

init:
	sub rsp, 0x208
	mov [rsp], rdi

cat:
	mov rdi, [rsp]
	lea rsi, [rel buffer]
	mov rdx, 0x200
	mov rax, MACH_SYSCALL(READ)
	syscall
	jc last
	test rax, rax
	je end

	mov rdi, 1
	lea rsi, [rel buffer]
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall

	jmp cat
		
last:
	mov rdi, 1
	lea rsi, [rel buffer]
	mov rdx, rax
	mov rax, MACH_SYSCALL(WRITE)
	syscall

end:
	mov rsp, rbp
	pop rbp
	ret
