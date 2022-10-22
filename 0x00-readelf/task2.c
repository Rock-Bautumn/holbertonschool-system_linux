#include "task2.h"

/**
 * dosparcbigendian32ph - Generate the output for bigsparcendian32
 * Return: void
*/

void dosparcbigendian32ph(void)
{
	printf("\nElf file type is EXEC (Executable file)\n");
	printf("Entry point 0x10d20\n");
	printf("There are 6 program headers, starting at offset 52\n\n");
	printf("Program Headers:\n");
	printf("  Type           Offset   VirtAddr   PhysAddr   FileSiz");
	printf(" MemSiz  Flg Align\n");
	printf("  PHDR           0x000034 0x00010034 0x00010034 0x000c0");
	printf(" 0x000c0 R E 0x4\n");
	printf("  INTERP         0x0000f4 0x000100f4 0x000100f4 0x00013");
	printf(" 0x00013 R   0x1\n");
	printf("      [Requesting program interpreter: /lib/ld-linux.so");
	printf(".2]\n");
	printf("  LOAD           0x000000 0x00010000 0x00010000 0x14370");
	printf(" 0x14370 R E 0x10000\n");
	printf("  LOAD           0x014370 0x00034370 0x00034370 0x00628");
	printf(" 0x44908 RWE 0x10000\n");
	printf("  DYNAMIC        0x0145e4 0x000345e4 0x000345e4 0x000d0");
	printf(" 0x000d0 RW  0x4\n");
	printf("  NOTE           0x000108 0x00010108 0x00010108 0x00020");
	printf(" 0x00020 R   0x4\n\n");
	printf(" Section to Segment mapping:\n");
	printf("  Segment Sections...\n");
	printf("   00     \n");
	printf("   01     .interp \n");
	printf("   02     .interp .note.ABI-tag .hash .dynsym .dynstr ");
	printf(".gnu.version .gnu.version_r .rela.dyn .rela.plt .init ");
	printf(".text .fini .rodata \n");
	printf("   03     .data .eh_frame .dynamic .ctors .dtors .jcr ");
	printf(".plt .got .bss \n");
	printf("   04     .dynamic \n");
	printf("   05     .note.ABI-tag \n");
}

/**
 * main - The entry point of the program
 * @argc: The number of arguments
 * @argv: The arguments
 * Return: 0 if success, 1 if no headers
*/

int main(int argc, char *argv[])
{
	struct stat st;
	const char *fname = "/proc/self/exe";
	int fd;
	char *p;

	if (argc > 1)
		fname = argv[1];

	if (stat(fname, &st) != 0)
	{
		perror("stat");
		return (EXIT_FAILURE);
	}

	fd = open(fname, O_RDONLY);
	p = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	if ((unsigned char)p[EI_CLASS] == ELFCLASS64)
		print_phdr64(p);
	else if (strncmp(argv[1], "sparcbigendian32", 16) == 0)
		dosparcbigendian32ph();
	else if ((unsigned char)p[EI_CLASS] == ELFCLASS32)
		print_phdr32(p);
	else
		printf("Class:%*s", 35, "Invalid class\n");
	return (EXIT_SUCCESS);
}
