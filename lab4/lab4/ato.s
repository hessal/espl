	.file	"ato.c"
	.intel_syntax noprefix
	.text
.globl ato
	.type	ato, @function
ato:
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	mov	rbp, rsp
	.cfi_offset 6, -16
	.cfi_def_cfa_register 6
	sub	rsp, 48
	mov	QWORD PTR [rbp-40], rdi
	mov	DWORD PTR [rbp-4], 0
	mov	DWORD PTR [rbp-8], 1
	mov	rax, QWORD PTR [rbp-40]
	mov	rdi, rax
	call	strlen
	mov	DWORD PTR [rbp-12], eax
	mov	DWORD PTR [rbp-16], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR [rbp-12]
	cdqe
	sub	rax, 1
	add	rax, QWORD PTR [rbp-40]
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	sub	eax, 48
	mov	DWORD PTR [rbp-20], eax
	mov	eax, DWORD PTR [rbp-20]
	imul	eax, DWORD PTR [rbp-8]
	mov	DWORD PTR [rbp-20], eax
	mov	eax, DWORD PTR [rbp-20]
	add	DWORD PTR [rbp-4], eax
	mov	edx, DWORD PTR [rbp-8]
	mov	eax, edx
	sal	eax, 2
	add	eax, edx
	add	eax, eax
	mov	DWORD PTR [rbp-8], eax
	sub	DWORD PTR [rbp-12], 1
.L2:
	cmp	DWORD PTR [rbp-12], 0
	jg	.L3
	mov	eax, DWORD PTR [rbp-4]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	ato, .-ato
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
