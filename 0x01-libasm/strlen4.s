	.file	"_strlen.c"
	.text
.Ltext0:
	.p2align 4
	.globl	asm_strlen
	.type	asm_strlen, @function
asm_strlen:
.LVL0:
.LFB0:
	.file 1 "_strlen.c"
	.loc 1 2 1 view -0
	.cfi_startproc
	.loc 1 2 1 is_stmt 0 view .LVU1
	endbr64
	.loc 1 3 2 is_stmt 1 view .LVU2
.LVL1:
	.loc 1 5 2 view .LVU3
	.loc 1 5 8 view .LVU4
	cmpb	$0, (%rdi)
	je	.L2
.LVL2:
.L3:
	.loc 1 6 3 view .LVU5
	.loc 1 5 8 view .LVU6
	.loc 1 6 3 view .LVU7
	.loc 1 5 8 view .LVU8
	.loc 1 5 8 is_stmt 0 view .LVU9
	jmp	.L3
.LVL3:
	.p2align 4,,10
	.p2align 3
.L2:
	.loc 1 7 2 is_stmt 1 view .LVU10
	.loc 1 8 1 is_stmt 0 view .LVU11
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	asm_strlen, .-asm_strlen
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x88
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF2
	.byte	0xc
	.long	.LASF3
	.long	.LASF4
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF5
	.byte	0x1
	.byte	0x1
	.byte	0xe
	.long	0x72
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.long	0x72
	.uleb128 0x3
	.string	"str"
	.byte	0x1
	.byte	0x1
	.byte	0x25
	.long	0x79
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x4
	.long	.LASF6
	.byte	0x1
	.byte	0x3
	.byte	0xf
	.long	0x72
	.long	.LLST0
	.long	.LVUS0
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.byte	0x7
	.long	.LASF0
	.uleb128 0x6
	.byte	0x8
	.long	0x86
	.uleb128 0x5
	.byte	0x1
	.byte	0x6
	.long	.LASF1
	.uleb128 0x7
	.long	0x7f
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LVUS0:
	.uleb128 .LVU3
	.uleb128 .LVU5
	.uleb128 .LVU10
	.uleb128 0
.LLST0:
	.quad	.LVL1-.Ltext0
	.quad	.LVL2-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL3-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	0
	.quad	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF5:
	.string	"asm_strlen"
.LASF6:
	.string	"size"
.LASF0:
	.string	"unsigned int"
.LASF3:
	.string	"_strlen.c"
.LASF1:
	.string	"char"
.LASF2:
	.string	"GNU C17 9.4.0 -mtune=generic -march=x86-64 -g -O3 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection"
.LASF4:
	.string	"/home/zakamiro/HolbertonProjects/holbertonschool-system_linux/0x01-asm"
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
