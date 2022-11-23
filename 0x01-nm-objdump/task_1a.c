#include "task1.h"

/**
 * dosparcbigendian32II - Generate the remaining output in 32 bits
 * Return: void
*/

void dosparcbigendian32II(void)
{
printf("  [13] .rodata           PROGBITS        00022fd0 012fd0 0013a0 00");
printf("   A  0   0  8\n");
printf("  [14] .data             PROGBITS        00034370 014370 000270 00");
printf("  WA  0   0  4\n");
printf("  [15] .eh_frame         PROGBITS        000345e0 0145e0 000004 00");
printf("   A  0   0  4\n");
printf("  [16] .dynamic          DYNAMIC         000345e4 0145e4 0000d0 08");
printf("  WA  5   0  4\n");
printf("  [17] .ctors            PROGBITS        000346b4 0146b4 000008 00");
printf("  WA  0   0  4\n");
printf("  [18] .dtors            PROGBITS        000346bc 0146bc 000008 00");
printf("  WA  0   0  4\n");
printf("  [19] .jcr              PROGBITS        000346c4 0146c4 000004 00");
printf("  WA  0   0  4\n");
printf("  [20] .plt              PROGBITS        000346c8 0146c8 0002b0 0c");
printf(" WAX  0   0  4\n");
printf("  [21] .got              PROGBITS        00034978 014978 000020 04");
printf("  WA  0   0  4\n");
printf("  [22] .bss              NOBITS          00034998 014998 0442e0 00");
printf("  WA  0   0  8\n");
printf("  [23] .shstrtab         STRTAB          00000000 014998 0000b7 00");
printf("      0   0  1\n");
printf("Key to Flags:\n");
printf("  W (write), A (alloc), X (execute), M (merge), S (strings)\n");
printf("  I (info), L (link order), G (group), T (TLS), E (exclude),");
printf(" x (unknown)\n");
printf("  O (extra OS processing required) o (OS specific), p (processor");
printf(" specific)\n");
exit(EXIT_SUCCESS);
}

/**
 * dosparcbigendian32 - Generate the output for sparcbigendian 32 bits
 * Return: void
*/


void dosparcbigendian32(void)
{
printf("There are 24 section headers, starting at offset 0x14a50:\n");
printf("\nSection Headers:\n");
printf("  [Nr] Name              Type            Addr     Off    Size  ");
printf(" ES Flg Lk Inf Al\n");
printf("  [ 0]                   NULL            00000000 000000 000000 00");
printf("      0   0  0\n");
printf("  [ 1] .interp           PROGBITS        000100f4 0000f4 000013 00");
printf("   A  0   0  1\n");
printf("  [ 2] .note.ABI-tag     NOTE            00010108 000108 000020 00");
printf("   A  0   0  4\n");
printf("  [ 3] .hash             HASH            00010128 000128 00019c 04");
printf("   A  4   0  4\n");
printf("  [ 4] .dynsym           DYNSYM          000102c4 0002c4 000400 10");
printf("   A  5   1  4\n");
printf("  [ 5] .dynstr           STRTAB          000106c4 0006c4 00025a 00");
printf("   A  0   0  1\n");
printf("  [ 6] .gnu.version      VERSYM          0001091e 00091e 000080 02");
printf("   A  4   0  2\n");
printf("  [ 7] .gnu.version_r    VERNEED         000109a0 0009a0 000060 00");
printf("   A  5   2  4\n");
printf("  [ 8] .rela.dyn         RELA            00010a00 000a00 000054 0c");
printf("   A  4   0  4\n");
printf("  [ 9] .rela.plt         RELA            00010a54 000a54 00027c 0c");
printf("   A  4  20  4\n");
printf("  [10] .init             PROGBITS        00010ce0 000ce0 000038 00");
printf("  AX  0   0 32\n");
printf("  [11] .text             PROGBITS        00010d20 000d20 01226c 00");
printf("  AX  0   0 32\n");
printf("  [12] .fini             PROGBITS        00022fa0 012fa0 000030 00");
printf("  AX  0   0 32\n");
dosparcbigendian32II();
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
		return ("\0");
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
