	.file	"_strlen.c"
	.text
	.p2align 4
	.globl	asm_strlen
	.type	asm_strlen, @function
asm_strlen:
.LFB0:
	.cfi_startproc
	endbr64
	cmpb	$0, (%rdi)
	je	.L2
.L3:
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L2:
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	asm_strlen, .-asm_strlen
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
