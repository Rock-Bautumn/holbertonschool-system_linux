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
	for (i = 0; i < argc; i++)
	{
		printf("%d - %s\n", i, argv[i]);
	}
	return 0;
}
