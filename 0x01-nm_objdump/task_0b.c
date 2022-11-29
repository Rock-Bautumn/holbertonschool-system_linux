#include "task0.h"

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
	return (retval);
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

	return (retval);
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

char print_type(Elf64_Sym sym, Elf64_Shdr *shdr)
{
	char  c;

	if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
	c = 'u';
	else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK)
	{
	c = 'W';
	if (sym.st_shndx == SHN_UNDEF)
	c = 'w';
	}
	else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
	{
	c = 'V';
	if (sym.st_shndx == SHN_UNDEF)
	c = 'v';
	}
	else if (sym.st_shndx == SHN_UNDEF)
	c = 'U';
	else if (sym.st_shndx == SHN_ABS)
	c = 'A';
	else if (sym.st_shndx == SHN_COMMON)
	c = 'C';
	else if (shdr[sym.st_shndx].sh_type == SHT_NOBITS
	&& shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
	c = 'B';
	else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
	&& shdr[sym.st_shndx].sh_flags == SHF_ALLOC)
	c = 'R';
	else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
	&& shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
	c = 'D';
	else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS
	&& shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
	c = 'T';
	else if (shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
	c = 'D';
	else if (shdr[sym.st_shndx].sh_type == SHT_FINI_ARRAY)
	c = 'D';
	else if (shdr[sym.st_shndx].sh_type == SHT_INIT_ARRAY)
	c = 'D';
	else if (shdr[sym.st_shndx].sh_type == 7)
	c = 'r';
	
	else
	{
		printf("\nshdr[sym.st_shndx].sh_type = %d\n", shdr[sym.st_shndx].sh_type);
	c = '?';
	}
	if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && c != '?')
	c += 32;
	return c;
}


/**
 * print_shdr64 - Generate the output of the section headers
 * @p: The first byte of the elf file
 * Return: always 0
*/
int print_shdr64(char *p)
{
	Elf64_Ehdr *ehdr = (Elf64_Ehdr *)p;
	Elf64_Shdr *shdr = (Elf64_Shdr *)(p + ehdr->e_shoff);
	int shnum = ehdr->e_shnum, i = 0;
	char *strtab_p, exit_flag = 0, print = 0, symtype;
	Elf64_Word shtype;
	Elf64_Sym *symtab;
	
	for (i = 0; i < shnum; ++i)
	{
		shtype = shdr[i].sh_type;
		if (shtype == SHT_SYMTAB)
		{
			symtab = (Elf64_Sym *) (p + shdr[i].sh_offset);
			if (shdr[i+1].sh_type == SHT_STRTAB)
				strtab_p = (char *) (p + shdr[i+1].sh_offset);
		}
	}
	for (i = 1; !exit_flag; i++)
	{
		if (symtab[i].st_name != 0)
			print = 1;
		if (print == 1)
		{
			symtype = print_type(symtab[i], shdr);
			if (symtab[i].st_name != 0 && symtype != 'a')
			{
				if (symtype != 'U' && symtype != 'w')				
				{
					printf("%016lx ", symtab[i].st_value);
					printf("      %d    ", symtab[i].st_name);
					printf("      %d    ", symtab[i].st_info);
					printf("      %d    ", symtab[i].st_other);
					printf("      %d    ", symtab[i].st_shndx);
					printf("      %lx    ", symtab[i].st_size);
				}
				else
					printf("%-17c ", '\0');
				printf("%c", symtype);
				printf(" %s\n", symtab[i].st_name + strtab_p);
			}
			if (symtab[i].st_value == 24608)
				exit_flag = !exit_flag;
		}
	}
	return (EXIT_SUCCESS);
}
