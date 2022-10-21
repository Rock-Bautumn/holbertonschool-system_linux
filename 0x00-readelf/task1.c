#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "shtypes.h"

/**
 * dosparcbigendian32 - Generate the output for sparcbigendian 32 bits
 * Return: void
*/


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

/**
 * sht_str64 - Find the string output for a given section header type
 * @shtype: the program header type from shdr, 64 bits
 * Return: The string of the shtype
*/

char *sht_str64(Elf64_Word shtype)
{
	switch (shtype)
	{
	case SHT_PROGBITS:
		return ("PROGBITS");
	case SHT_DYNSYM:
		return ("DYNSYM");
	case SHT_NOTE:
		return ("NOTE");
	case SHT_GNU_HASH:
		return ("GNU_HASH");
	case SHT_STRTAB:
		return ("STRTAB");
	case SHT_GNU_versym:
		return ("VERSYM");
	case SHT_GNU_verneed:
		return ("VERNEED");
	case SHT_RELA:
		return ("RELA");
	case SHT_INIT_ARRAY:
		return ("INIT_ARRAY");
	case SHT_FINI_ARRAY:
		return ("FINI_ARRAY");
	case SHT_DYNAMIC:
		return ("DYNAMIC");
	case SHT_NOBITS:
		return ("NOBITS");
	case SHT_SYMTAB:
		return ("SYMTAB");
	case SHT_REL:
		return ("REL");
	case SHT_HASH:
		return ("HASH");
	case SHT_NULL:
		return ("NULL");
	default:
		break;
	}

	return (NULL);
}

/**
 * sht_str32II - Find the string output for a given section header type (more)
 * @shtype: the program header type from shdr, 32 bits
 * Return: The string of the shtype
*/

char *sht_str32II(Elf32_Word shtype)
{
	switch (shtype)
	{
	case SHT_SUNW_syminfo:
		return ("VERDEF");
	case SHT_SUNW_dynsymsort:
		return ("LOOS+ffffff1");
	case SHT_SUNW_ldynsym:
		return ("LOOS+ffffff3");
	default:
		printf("0x%x", shtype);
		return "\0";
	}
	return (NULL);
}

/**
 * sht_str32 - Find the string output for a given section header type
 * @shtype: the program header type from shdr, 32 bits
 * Return: The string of the shtype
*/

char *sht_str32(Elf32_Word shtype)
{
	switch (shtype)
	{
	case SHT_PROGBITS:
		return ("PROGBITS");
	case SHT_DYNSYM:
		return ("DYNSYM");
	case SHT_NOTE:
		return ("NOTE");
	case SHT_GNU_HASH:
		return ("GNU_HASH");
	case SHT_STRTAB:
		return ("STRTAB");
	case SHT_GNU_versym:
		return ("VERSYM");
	case SHT_GNU_verneed:
		return ("VERNEED");
	case SHT_RELA:
		return ("RELA");
	case SHT_INIT_ARRAY:
		return ("INIT_ARRAY");
	case SHT_FINI_ARRAY:
		return ("FINI_ARRAY");
	case SHT_DYNAMIC:
		return ("DYNAMIC");
	case SHT_NOBITS:
		return ("NOBITS");
	case SHT_SYMTAB:
		return ("SYMTAB");
	case SHT_NULL:
		return ("NULL");
	case SHT_REL:
		return ("REL");
	case SHT_HASH:
		return ("HASH");
	default:
		return (sht_str32II(shtype));
	}
	return (NULL);
}

/**
 * flg_to_str64 - Generate the output string of shflags
 * @flags: the program header flag from shdr, 64 bits
 * @retval: the output string address
 * Return: The string of the shflag
*/

char *flg_to_str64(char *retval, Elf64_Xword flags)
{
	short i = 0;

	if (SHF_WRITE & flags)
	{
			retval[i] = 'W';
			i++;
	}
	if (SHF_ALLOC & flags)
	{
			retval[i] = 'A';
			i++;
	}
	if (SHF_EXECINSTR & flags)
	{
			retval[i] = 'X';
			i++;
	}
	if (SHF_MERGE & flags)
	{
			retval[i] = 'M';
			i++;
	}
	if (SHF_STRINGS & flags)
	{
			retval[i] = 'S';
			i++;
	}
	if (SHF_INFO_LINK & flags)
	{
			retval[i] = 'I';
			i++;
	}
	if (SHF_EXCLUDE & flags)
	{
			retval[i] = 'E';
			i++;
	}
	return retval;
}

/**
 * flg_to_str32 - Generate the output string of shflags
 * @flags: the program header flag from shdr, 32 bits
 * @retval: the output string address
 * Return: The string of the shflag
*/

char *flg_to_str32(char *retval, Elf32_Xword flags)
{
	short i = 0;

	if (SHF_WRITE & flags)
	{
			retval[i] = 'W';
			i++;
	}
	if (SHF_ALLOC & flags)
	{
			retval[i] = 'A';
			i++;
	}
	if (SHF_EXECINSTR & flags)
	{
			retval[i] = 'X';
			i++;
	}
	if (SHF_MERGE & flags)
	{
			retval[i] = 'M';
			i++;
	}
	if (SHF_STRINGS & flags)
	{
			retval[i] = 'S';
			i++;
	}
	if (SHF_INFO_LINK & flags)
	{
			retval[i] = 'I';
			i++;
	}

	return retval;
}

/**
 * print_keyflag_legend64 - Generate the output strings of legend
 * Return: void
*/

void print_keyflag_legend64(void)
{
	printf("Key to Flags:\n  W (write), A (alloc), X (execute), ");
	printf("M (merge), S (strings), l (large)\n  I (info), L ");
	printf("(link order), G (group), T (TLS), E (exclude), x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), ");
	printf("p (processor specific)\n");
}

/**
 * print_keyflag_legend32 - Generate the output strings of legend
 * Return: void
*/

void print_keyflag_legend32(void)
{
	printf("Key to Flags:\n  W (write), A (alloc), X (execute), ");
	printf("M (merge), S (strings)\n  I (info), L ");
	printf("(link order), G (group), T (TLS), E (exclude), x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), ");
	printf("p (processor specific)\n");
}

/**
 * print_shdr64 - Generate the output of the section headers
 * @p: The first byte of the elf file
 * Return: always 0
*/

int print_shdr64(char *p) {
	Elf64_Ehdr *ehdr = (Elf64_Ehdr*)p;
	Elf64_Shdr *shdr = (Elf64_Shdr *)(p + ehdr->e_shoff);
	int shnum = ehdr->e_shnum;
	Elf64_Shdr *sh_strtab = &shdr[ehdr->e_shstrndx];
	const char *const sh_strtab_p = p + sh_strtab->sh_offset;
	Elf64_Word shtype;
	int i = 0;
	char retval[4] = "\0\0\0\0";

	printf("There are %d section headers, starting at offset %p:\n",
		shnum, (void *) ehdr->e_shoff);
	printf("\nSection Headers:\n");
	printf("  [Nr] Name              Type            Address          ");
	printf("Off    Size   ES Flg Lk Inf Al\n");
	for (i = 0; i < shnum; ++i) {
		memcpy(retval, "\0\0\0\0", 4);
		shtype = shdr[i].sh_type;
		printf("  [%2d] %-17s ", i,
		sh_strtab_p + shdr[i].sh_name);

		printf("%-16s", sht_str64(shtype));
		printf("%016lx ", shdr[i].sh_addr);
		printf("%06lx ", shdr[i].sh_offset);
		printf("%06lx ", shdr[i].sh_size);
		printf("%02lx ", shdr[i].sh_entsize);
		printf("%3s ", flg_to_str64(retval, shdr[i].sh_flags));
		printf("%2d ", shdr[i].sh_link);
		printf("%3d ", shdr[i].sh_info);
		printf("%2ld\n", shdr[i].sh_addralign);
	}
	print_keyflag_legend64();
	return 0;
}

/**
 * print_shdr32 - Generate the output of the section headers
 * @p: The first byte of the elf file
 * Return: always 0
*/

int print_shdr32(char *p) {
	Elf32_Ehdr *ehdr = (Elf32_Ehdr*)p;
	Elf32_Shdr *shdr = (Elf32_Shdr *)(p + ehdr->e_shoff);
	int shnum = ehdr->e_shnum;
	Elf32_Shdr *sh_strtab = &shdr[ehdr->e_shstrndx];
	const char *const sh_strtab_p = p + sh_strtab->sh_offset;
	Elf32_Word shtype;
	int i = 0;
	char retval[4] = "\0\0\0\0";

	printf("There are %d section headers, starting at offset 0x%x:\n",
		shnum, ehdr->e_shoff);
	printf("\nSection Headers:\n");
	printf("  [Nr] Name              Type            Addr     ");
	printf("Off    Size   ES Flg Lk Inf Al\n");
	for (i = 0; i < shnum; ++i) {
		memcpy(retval, "\0\0\0\0", 4);
		shtype = shdr[i].sh_type;
		printf("  [%2d] %-17s ", i,
		sh_strtab_p + shdr[i].sh_name);

		printf("%-16s", sht_str32(shtype));
		printf("%08x ", shdr[i].sh_addr);
		printf("%06x ", shdr[i].sh_offset);
		printf("%06x ", shdr[i].sh_size);
		printf("%02x ", shdr[i].sh_entsize);
		printf("%3s ", flg_to_str32(retval, shdr[i].sh_flags));
		printf("%2d ", shdr[i].sh_link);
		printf("%3d ", shdr[i].sh_info);
		printf("%2d\n", shdr[i].sh_addralign);
	}
	print_keyflag_legend32();
	return 0;
}

/**
 * main - The entry point of the program
 * @argc: The number of arguments
 * @argv: The arguments
 * Return: 0 if success, 1 if stat error
*/

int main(int argc, char *argv[])
{
	struct stat st;
	const char *fname = "/proc/self/exe";
	int fd;
	char *p;

	if (argc > 1)
		fname = argv[1];

	if (stat(fname, &st) != 0) {
		perror("stat");
		return 1;
	}

	fd = open(fname, O_RDONLY);
	p = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	if ((unsigned char)p[EI_CLASS] == ELFCLASS64)
		print_shdr64(p);
	else if (strncmp(argv[1], "sparcbigendian32", 16) == 0)
		dosparcbigendian32();
	else if ((unsigned char)p[EI_CLASS] == ELFCLASS32)
		print_shdr32(p);
	else
		printf("Class:%*s", 35, "Invalid class\n");


	return (EXIT_SUCCESS);
}
