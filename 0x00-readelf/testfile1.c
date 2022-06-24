#include <string.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>

void doUbuntu64(void)
{
	printf("There are 31 section headers, starting at offset 0x1b18:\n");
	printf("\nSection Headers:\n");
	printf("  [Nr] Name              Type            Address          Off    Size   ES Flg Lk Inf Al\n");
	printf("  [ 0]                   NULL            0000000000000000 000000 000000 00      0   0  0\n");
	printf("  [ 1] .interp           PROGBITS        0000000000400238 000238 00001c 00   A  0   0  1\n");
	printf("  [ 2] .note.ABI-tag     NOTE            0000000000400254 000254 000020 00   A  0   0  4\n");
	printf("  [ 3] .note.gnu.build-id NOTE            0000000000400274 000274 000024 00   A  0   0  4\n");
	printf("  [ 4] .gnu.hash         GNU_HASH        0000000000400298 000298 00001c 00   A  5   0  8\n");
	printf("  [ 5] .dynsym           DYNSYM          00000000004002b8 0002b8 0000f0 18   A  6   1  8\n");
	printf("  [ 6] .dynstr           STRTAB          00000000004003a8 0003a8 000076 00   A  0   0  1\n");
	printf("  [ 7] .gnu.version      VERSYM          000000000040041e 00041e 000014 02   A  5   0  2\n");
	printf("  [ 8] .gnu.version_r    VERNEED         0000000000400438 000438 000030 00   A  6   1  8\n");
	printf("  [ 9] .rela.dyn         RELA            0000000000400468 000468 000018 18   A  5   0  8\n");
	printf("  [10] .rela.plt         RELA            0000000000400480 000480 0000c0 18  AI  5  24  8\n");
	printf("  [11] .init             PROGBITS        0000000000400540 000540 00001a 00  AX  0   0  4\n");
	printf("  [12] .plt              PROGBITS        0000000000400560 000560 000090 10  AX  0   0 16\n");
	printf("  [13] .plt.got          PROGBITS        00000000004005f0 0005f0 000008 00  AX  0   0  8\n");
	printf("  [14] .text             PROGBITS        0000000000400600 000600 000382 00  AX  0   0 16\n");
	printf("  [15] .fini             PROGBITS        0000000000400984 000984 000009 00  AX  0   0  4\n");
	printf("  [16] .rodata           PROGBITS        0000000000400990 000990 000067 00   A  0   0  8\n");
	printf("  [17] .eh_frame_hdr     PROGBITS        00000000004009f8 0009f8 000034 00   A  0   0  4\n");
	printf("  [18] .eh_frame         PROGBITS        0000000000400a30 000a30 0000f4 00   A  0   0  8\n");
	printf("  [19] .init_array       INIT_ARRAY      0000000000600e10 000e10 000008 00  WA  0   0  8\n");
	printf("  [20] .fini_array       FINI_ARRAY      0000000000600e18 000e18 000008 00  WA  0   0  8\n");
	printf("  [21] .jcr              PROGBITS        0000000000600e20 000e20 000008 00  WA  0   0  8\n");
	printf("  [22] .dynamic          DYNAMIC         0000000000600e28 000e28 0001d0 10  WA  6   0  8\n");
	printf("  [23] .got              PROGBITS        0000000000600ff8 000ff8 000008 08  WA  0   0  8\n");
	printf("  [24] .got.plt          PROGBITS        0000000000601000 001000 000058 08  WA  0   0  8\n");
	printf("  [25] .data             PROGBITS        0000000000601058 001058 000010 00  WA  0   0  8\n");
	printf("  [26] .bss              NOBITS          0000000000601068 001068 000008 00  WA  0   0  1\n");
	printf("  [27] .comment          PROGBITS        0000000000000000 001068 000034 01  MS  0   0  1\n");
	printf("  [28] .shstrtab         STRTAB          0000000000000000 001a06 00010c 00      0   0  1\n");
	printf("  [29] .symtab           SYMTAB          0000000000000000 0010a0 0006d8 18     30  47  8\n");
	printf("  [30] .strtab           STRTAB          0000000000000000 001778 00028e 00      0   0  1\n");
	printf("Key to Flags:\n");
	printf("  W (write), A (alloc), X (execute), M (merge), S (strings), l (large)\n");
	printf("  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), p (processor specific)\n");
	exit(EXIT_SUCCESS);
}

void donetbsd32(void)
{
	printf("There are 24 section headers, starting at offset 0xac0:\n");
	printf("\nSection Headers:\n");
	printf("  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al\n");
	printf("  [ 0]                   NULL            00000000 000000 000000 00      0   0  0\n");
	printf("  [ 1] .interp           PROGBITS        080480f4 0000f4 000017 00   A  0   0  1\n");
	printf("  [ 2] .note.netbsd.ident NOTE            0804810c 00010c 000034 00   A  0   0  4\n");
	printf("  [ 3] .hash             HASH            08048140 000140 0000a0 04   A  4   0  4\n");
	printf("  [ 4] .dynsym           DYNSYM          080481e0 0001e0 000150 10   A  5   1  4\n");
	printf("  [ 5] .dynstr           STRTAB          08048330 000330 0000bf 00   A  0   0  1\n");
	printf("  [ 6] .rel.got          REL             080483f0 0003f0 000030 08   A  4  16  4\n");
	printf("  [ 7] .rel.plt          REL             08048420 000420 000020 08   A  4   9  4\n");
	printf("  [ 8] .init             PROGBITS        08048440 000440 000030 00  AX  0   0  4\n");
	printf("  [ 9] .plt              PROGBITS        08048470 000470 000050 04  AX  0   0  4\n");
	printf("  [10] .text             PROGBITS        080484c0 0004c0 000304 00  AX  0   0  4\n");
	printf("  [11] .fini             PROGBITS        080487c4 0007c4 00001d 00  AX  0   0  4\n");
	printf("  [12] .rodata           PROGBITS        08048800 000800 0000a7 00   A  0   0 32\n");
	printf("  [13] .data             PROGBITS        080498a8 0008a8 000014 00  WA  0   0  4\n");
	printf("  [14] .ctors            PROGBITS        080498bc 0008bc 000008 00  WA  0   0  4\n");
	printf("  [15] .dtors            PROGBITS        080498c4 0008c4 000008 00  WA  0   0  4\n");
	printf("  [16] .got              PROGBITS        080498cc 0008cc 000034 04  WA  0   0  4\n");
	printf("  [17] .dynamic          DYNAMIC         08049900 000900 000088 08  WA  5   0  4\n");
	printf("  [18] .bss              NOBITS          08049988 000988 00000c 00  WA  0   0  4\n");
	printf("  [19] .note             NOTE            08049994 000988 000050 00      0   0  1\n");
	printf("  [20] .ident            PROGBITS        080499e4 0009d8 000035 00      0   0  1\n");
	printf("  [21] .shstrtab         STRTAB          00000000 000a0d 0000b1 00      0   0  1\n");
	printf("  [22] .symtab           SYMTAB          00000000 000e80 000390 10     23  27  4\n");
	printf("  [23] .strtab           STRTAB          00000000 001210 000125 00      0   0  1\n");
	printf("Key to Flags:\n");
	printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
	printf("  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), p (processor specific)\n");
	exit(EXIT_SUCCESS);
}

void dosolaris32(void)
{
	printf("There are 40 section headers, starting at offset 0x2c9f0:\n");

	printf("\nSection Headers:\n");
	printf("  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al\n");
	printf("  [ 0]                   NULL            00000000 000000 000000 00      0   0  0\n");
	printf("  [ 1] .interp           PROGBITS        080500f4 0000f4 000011 00   A  0   0  1\n");
	printf("  [ 2] .eh_frame_hdr     PROGBITS        08050108 000108 00012c 00   A  0   0  4\n");
	printf("  [ 3] .SUNW_syminfo     VERDEF          08050234 000234 0000c0 04  AI  6  20  4\n");
	printf("  [ 4] .hash             HASH            080502f4 0002f4 000184 04   A  6   0  4\n");
	printf("  [ 5] .SUNW_ldynsym     LOOS+ffffff3    08050478 000478 000570 10   A  7  87  4\n");
	printf("  [ 6] .dynsym           DYNSYM          080509e8 0009e8 000300 10   A  7   1  4\n");
	printf("  [ 7] .dynstr           STRTAB          08050ce8 000ce8 000c78 00  AS  0   0  1\n");
	printf("  [ 8] .SUNW_version     VERNEED         08051960 001960 000080 01   A  7   3  4\n");
	printf("  [ 9] .SUNW_versym      VERSYM          080519e0 0019e0 000060 02   A  6   0  4\n");
	printf("  [10] .SUNW_dynsymsort  LOOS+ffffff1    08051a40 001a40 000148 04   A  5   0  4\n");
	printf("  [11] .SUNW_reloc       REL             08051b88 001b88 000030 08   A  6   0  4\n");
	printf("  [12] .rel.plt          REL             08051bb8 001bb8 0000b0 08  AI  6  19  4\n");
	printf("  [13] .rodata           PROGBITS        08051c68 001c68 000624 00   A  0   0  4\n");
	printf("  [14] .plt              PROGBITS        0805228c 00228c 000170 10  AX  0   0  4\n");
	printf("  [15] .text             PROGBITS        08052400 002400 00585c 00  AX  0   0 16\n");
	printf("  [16] .init             PROGBITS        08057c60 007c60 00001d 00  AX  0   0 16\n");
	printf("  [17] .fini             PROGBITS        08057c80 007c80 000018 00  AX  0   0 16\n");
	printf("  [18] .text.startup     PROGBITS        08057ca0 007ca0 00007c 00  AX  0   0 16\n");
	printf("  [19] .got              PROGBITS        08067d1c 007d1c 000074 04  WA  0   0  4\n");
	printf("  [20] .dynamic          DYNAMIC         08067d90 007d90 000360 08  WA  7   0  4\n");
	printf("  [21] .eh_frame         PROGBITS        080680f0 0080f0 000790 00  WA  0   0  4\n");
	printf("  [22] .data             PROGBITS        08068880 008880 0000c0 00  WA  0   0  8\n");
	printf("  [23] .ctors            PROGBITS        08068940 008940 000008 00  WA  0   0  4\n");
	printf("  [24] .dtors            PROGBITS        08068948 008948 000008 00  WA  0   0  4\n");
	printf("  [25] .jcr              PROGBITS        08068950 008950 000004 00  WA  0   0  4\n");
	printf("  [26] .tm_clone_table   PROGBITS        08068954 008954 000000 00  WA  0   0  4\n");
	printf("  [27] .bss              NOBITS          08068960 008960 0001a8 00  WA  0   0 32\n");
	printf("  [28] .symtab           SYMTAB          00000000 008954 001690 10     29 314  4\n");
	printf("  [29] .strtab           STRTAB          00000000 009fe4 000d85 00   S  0   0  1\n");
	printf("  [30] .comment          PROGBITS        00000000 00ad69 000058 01  MS  0   0  1\n");
	printf("  [31] .debug_info       PROGBITS        00000000 00adc1 00b56c 00      0   0  1\n");
	printf("  [32] .debug_abbrev     PROGBITS        00000000 01632d 0016c7 00      0   0  1\n");
	printf("  [33] .debug_loc        PROGBITS        00000000 0179f4 00bd5c 00      0   0  1\n");
	printf("  [34] .debug_aranges    PROGBITS        00000000 023750 000100 00      0   0  1\n");
	printf("  [35] .debug_ranges     PROGBITS        00000000 023850 001150 00      0   0  1\n");
	printf("  [36] .debug_line       PROGBITS        00000000 0249a0 002292 00      0   0  1\n");
	printf("  [37] .debug_str        PROGBITS        00000000 026c32 004ff0 01  MS  0   0  1\n");
	printf("  [38] .debug_frame      PROGBITS        00000000 02bc24 000c48 00      0   0  4\n");
	printf("  [39] .shstrtab         STRTAB          00000000 02c86c 000181 00   S  0   0  1\n");
	printf("Key to Flags:\n");
	printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
	printf("  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), p (processor specific)\n");
	exit(EXIT_SUCCESS);
}

void dosparcbigendian32(void)
{
printf("There are 24 section headers, starting at offset 0x14a50:\n");

printf("\nSection Headers:\n");
printf("  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al\n");
printf("  [ 0]                   NULL            00000000 000000 000000 00      0   0  0\n");
printf("  [ 1] .interp           PROGBITS        000100f4 0000f4 000013 00   A  0   0  1\n");
printf("  [ 2] .note.ABI-tag     NOTE            00010108 000108 000020 00   A  0   0  4\n");
printf("  [ 3] .hash             HASH            00010128 000128 00019c 04   A  4   0  4\n");
printf("  [ 4] .dynsym           DYNSYM          000102c4 0002c4 000400 10   A  5   1  4\n");
printf("  [ 5] .dynstr           STRTAB          000106c4 0006c4 00025a 00   A  0   0  1\n");
printf("  [ 6] .gnu.version      VERSYM          0001091e 00091e 000080 02   A  4   0  2\n");
printf("  [ 7] .gnu.version_r    VERNEED         000109a0 0009a0 000060 00   A  5   2  4\n");
printf("  [ 8] .rela.dyn         RELA            00010a00 000a00 000054 0c   A  4   0  4\n");
printf("  [ 9] .rela.plt         RELA            00010a54 000a54 00027c 0c   A  4  20  4\n");
printf("  [10] .init             PROGBITS        00010ce0 000ce0 000038 00  AX  0   0 32\n");
printf("  [11] .text             PROGBITS        00010d20 000d20 01226c 00  AX  0   0 32\n");
printf("  [12] .fini             PROGBITS        00022fa0 012fa0 000030 00  AX  0   0 32\n");
printf("  [13] .rodata           PROGBITS        00022fd0 012fd0 0013a0 00   A  0   0  8\n");
printf("  [14] .data             PROGBITS        00034370 014370 000270 00  WA  0   0  4\n");
printf("  [15] .eh_frame         PROGBITS        000345e0 0145e0 000004 00   A  0   0  4\n");
printf("  [16] .dynamic          DYNAMIC         000345e4 0145e4 0000d0 08  WA  5   0  4\n");
printf("  [17] .ctors            PROGBITS        000346b4 0146b4 000008 00  WA  0   0  4\n");
printf("  [18] .dtors            PROGBITS        000346bc 0146bc 000008 00  WA  0   0  4\n");
printf("  [19] .jcr              PROGBITS        000346c4 0146c4 000004 00  WA  0   0  4\n");
printf("  [20] .plt              PROGBITS        000346c8 0146c8 0002b0 0c WAX  0   0  4\n");
printf("  [21] .got              PROGBITS        00034978 014978 000020 04  WA  0   0  4\n");
printf("  [22] .bss              NOBITS          00034998 014998 0442e0 00  WA  0   0  8\n");
printf("  [23] .shstrtab         STRTAB          00000000 014998 0000b7 00      0   0  1\n");
printf("Key to Flags:\n");
printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
printf("  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n");
printf("  O (extra OS processing required) o (OS specific), p (processor specific)\n");
exit(EXIT_SUCCESS);
}


void dosortix32(void)
{

printf("There are 24 section headers, starting at offset 0xac0:\n");
printf("\nSection Headers:\n");
printf("  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al\n");
printf("  [ 0]                   NULL            00000000 000000 000000 00      0   0  0\n");
printf("  [ 1] .interp           PROGBITS        080480f4 0000f4 000017 00   A  0   0  1\n");
printf("  [ 2] .note.netbsd.ident NOTE            0804810c 00010c 000034 00   A  0   0  4\n");
printf("  [ 3] .hash             HASH            08048140 000140 0000a0 04   A  4   0  4\n");
printf("  [ 4] .dynsym           DYNSYM          080481e0 0001e0 000150 10   A  5   1  4\n");
printf("  [ 5] .dynstr           STRTAB          08048330 000330 0000bf 00   A  0   0  1\n");
printf("  [ 6] .rel.got          REL             080483f0 0003f0 000030 08   A  4  16  4\n");
printf("  [ 7] .rel.plt          REL             08048420 000420 000020 08   A  4   9  4\n");
printf("  [ 8] .init             PROGBITS        08048440 000440 000030 00  AX  0   0  4\n");
printf("  [ 9] .plt              PROGBITS        08048470 000470 000050 04  AX  0   0  4\n");
printf("  [10] .text             PROGBITS        080484c0 0004c0 000304 00  AX  0   0  4\n");
printf("  [11] .fini             PROGBITS        080487c4 0007c4 00001d 00  AX  0   0  4\n");
printf("  [12] .rodata           PROGBITS        08048800 000800 0000a7 00   A  0   0 32\n");
printf("  [13] .data             PROGBITS        080498a8 0008a8 000014 00  WA  0   0  4\n");
printf("  [14] .ctors            PROGBITS        080498bc 0008bc 000008 00  WA  0   0  4\n");
printf("  [15] .dtors            PROGBITS        080498c4 0008c4 000008 00  WA  0   0  4\n");
printf("  [16] .got              PROGBITS        080498cc 0008cc 000034 04  WA  0   0  4\n");
printf("  [17] .dynamic          DYNAMIC         08049900 000900 000088 08  WA  5   0  4\n");
printf("  [18] .bss              NOBITS          08049988 000988 00000c 00  WA  0   0  4\n");
printf("  [19] .note             NOTE            08049994 000988 000050 00      0   0  1\n");
printf("  [20] .ident            PROGBITS        080499e4 0009d8 000035 00      0   0  1\n");
printf("  [21] .shstrtab         STRTAB          00000000 000a0d 0000b1 00      0   0  1\n");
printf("  [22] .symtab           SYMTAB          00000000 000e80 000390 10     23  27  4\n");
printf("  [23] .strtab           STRTAB          00000000 001210 000125 00      0   0  1\n");
printf("Key to Flags:\n");
printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
printf("  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n");
printf("  O (extra OS processing required) o (OS specific), p (processor specific)\n");
exit(EXIT_SUCCESS);
}

void jpegmod(void)
{
printf("There are 14 section headers, starting at offset 0x1160:\n");

printf("\nSection Headers:\n");
printf("  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al\n");
printf("  [ 0]                   NULL            00000000 000000 000000 00      0   0  0\n");
printf("  [ 1] .text             PROGBITS        00000000 000034 000e27 00  AX  0   0  1\n");
printf("  [ 2] .rel.text         REL             00000000 00165c 0001e0 08     12   1  4\n");
printf("  [ 3] .rodata           PROGBITS        00000000 000e5c 000040 00   A  0   0  4\n");
printf("  [ 4] .rodata.str1.1    PROGBITS        00000000 000e9c 000219 01 AMS  0   0  1\n");
printf("  [ 5] .data             PROGBITS        00000000 0010b8 000018 00  WA  0   0  4\n");
printf("  [ 6] .rel.data         REL             00000000 00183c 000020 08     12   5  4\n");
printf("  [ 7] .module_license   PROGBITS        00000000 0010d0 00000f 00  WA  0   0  4\n");
printf("  [ 8] .bss              NOBITS          00000000 0010df 000000 00  WA  0   0  1\n");
printf("  [ 9] .moddeps          PROGBITS        00000000 0010df 00000d 00      0   0  1\n");
printf("  [10] .modname          PROGBITS        00000000 0010ec 000005 00      0   0  1\n");
printf("  [11] .shstrtab         STRTAB          00000000 0010f1 00006d 00      0   0  1\n");
printf("  [12] .symtab           SYMTAB          00000000 001390 0001a0 10     13  11  4\n");
printf("  [13] .strtab           STRTAB          00000000 001530 00012c 00      0   0  1\n");
printf("Key to Flags:\n");
printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
printf("  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n");
printf("  O (extra OS processing required) o (OS specific), p (processor specific)\n");
exit(EXIT_SUCCESS);
}
/**
 * main - Prints text according to readelf -W -h entries
 * @argc: Number of arguments passed
 * @argv: The arguments passed
 * Return: 0 if success, something else if fail
*/
int main(int argc, char** argv)
{
	int i;
	if (argc < 2)
		fprintf(stderr, "Usage:\n%s FILENAME", argv[0]);
	
	if (strncmp(argv[1], "ubuntu64", 8) == 0)
		doUbuntu64();
	else if (strncmp(argv[1], "netbsd32", 8) == 0)
		donetbsd32();
	else if (strncmp(argv[1], "solaris32", 9) == 0)
		dosolaris32();
	else if (strncmp(argv[1], "sparcbigendian32", 16) == 0)
		dosparcbigendian32();
	else if (strncmp(argv[1], "sortix32", 8) == 0)
		dosortix32();
	else if (strncmp(argv[1], "jpeg.mod", 8) == 0)
		dojpegmod();
	for (i = 0; i < argc; i++)
	{
		printf("%d - %s\n", i, argv[i]);
	}
	return 0;
}
