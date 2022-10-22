#include "task2.h"

/**
 * phflag_to_str32 - Generate the output string of phflags
 * @phflag: the program header flag from phdr, 32 bits
 * @phtype: the output string address
 * Return: The string of the phflag
*/

char *phflag_to_str32(Elf32_Word phflag, char *phtype)
{
	memcpy(phtype, "   ", 4);
	if (phflag & PF_R)
		phtype[0] = 'R';
	if (phflag & PF_W)
		phtype[1] = 'W';
	if (phflag & PF_X)
		phtype[2] = 'E';
	return (phtype);
}

/**
 * print_segments64 - Generate the output from segments, 64 bit
 * @p: The first byte of the elf file, 64 bit
 * Return: void
*/

void print_segments64(char *p)
{
	Elf64_Ehdr *ehdr = (Elf64_Ehdr *)p;
	Elf64_Phdr *phdr = (Elf64_Phdr *)(p + ehdr->e_phoff);
	Elf64_Shdr *shdr = (Elf64_Shdr *)(p + ehdr->e_shoff);
	int phnum = ehdr->e_phnum;
	int shnum = ehdr->e_shnum;
	Elf64_Shdr *sh_strtab = &shdr[ehdr->e_shstrndx];
	const char *const sh_strtab_p = p + sh_strtab->sh_offset;
	int i = 0, j = 0;
	Elf64_Off pl, ph, sl, sh;

	printf("\n Section to Segment mapping:\n  Segment Sections...\n");
	(void) phdr;
	(void) sh_strtab_p;

	for (i = 0; i < phnum; ++i)
	{
		pl = phdr[i].p_offset;
		ph = phdr[i].p_offset + phdr[i].p_memsz;
		printf("   %02d     ", i);
		for (j = 0; j < shnum; ++j)
		{
			if (shdr[j].sh_addr == 0 || shdr[j].sh_size == 0)
				continue;
			sl = shdr[j].sh_offset;
			sh = shdr[j].sh_offset + shdr[j].sh_size;
			if (pl <= sl && sh <= ph)
				printf("%s ", sh_strtab_p + shdr[j].sh_name);
		}
		printf("\n");
	}
}
/**
 * print_segments32 - Generate the output from segments, 32 bit
 * @p: The first byte of the elf file
 * Return: void
*/

void print_segments32(char *p)
{
	Elf32_Ehdr *ehdr = (Elf32_Ehdr *)p;
	Elf32_Phdr *phdr = (Elf32_Phdr *)(p + ehdr->e_phoff);
	Elf32_Shdr *shdr = (Elf32_Shdr *)(p + ehdr->e_shoff);
	int phnum = ehdr->e_phnum;
	int shnum = ehdr->e_shnum;
	Elf32_Shdr *sh_strtab = &shdr[ehdr->e_shstrndx];
	const char *const sh_strtab_p = p + sh_strtab->sh_offset;
	int i = 0, j = 0;
	Elf32_Off pl, ph, sl, sh;

	printf("\n Section to Segment mapping:\n  Segment Sections...\n");
	(void) phdr;
	(void) sh_strtab_p;

	for (i = 0; i < phnum; ++i)
	{
		pl = phdr[i].p_offset;
		ph = phdr[i].p_offset + phdr[i].p_memsz;
		printf("   %02d     ", i);
		for (j = 0; j < shnum; ++j)
		{
			if (shdr[j].sh_addr == 0 || shdr[j].sh_size == 0)
				continue;
			sl = shdr[j].sh_offset;
			sh = shdr[j].sh_offset + shdr[j].sh_size;
			if (pl <= sl && sh <= ph)
				printf("%s ", sh_strtab_p + shdr[j].sh_name);
		}
		printf("\n");
	}
}

/**
 * print_phdr64 - Generate the output from program headers, 64 bit
 * @p: The first byte of the elf file
 * Return: 0 if success, 1 if no headers
*/

int print_phdr64(char *p)
{
	Elf64_Ehdr *ehdr = (Elf64_Ehdr *)p;
	Elf64_Phdr *phdr = (Elf64_Phdr *)(p + ehdr->e_phoff);
	Elf64_Off phoff = ehdr->e_phoff;
	int phnum = ehdr->e_phnum;
	int i = 0;
	char phtype[4] = "   \0";

	if (phnum == 0)
	{
		printf("\nThere are no program headers in this file.\n");
		return (EXIT_FAILURE);
	}

	printf("\nElf file type is %s\n", etype_to_str64(ehdr->e_type));
	printf("Entry point 0x%lx\nThere are ", ehdr->e_entry);
	printf("%d program headers, starting at offset %ld", phnum, phoff);
	printf("\n\nProgram Headers:\n  Type           Offset   VirtAddr");
	printf("           PhysAddr           FileSiz  MemSiz   Flg Align\n");

	for (i = 0; i < phnum; ++i)
	{
		printf("  %-13s  ", phtype_to_str64(phdr[i].p_type));
		printf("0x%06lx ", phdr[i].p_offset);
		printf("0x%016lx ", phdr[i].p_vaddr);
		printf("0x%016lx ", phdr[i].p_paddr);
		printf("0x%06lx ", phdr[i].p_filesz);
		printf("0x%06lx ", phdr[i].p_memsz);
		printf("%s ", phflag_to_str64(phdr[i].p_flags, phtype));
		printf("0x%lx", phdr[i].p_align);
		printf("\n");
		if (phdr[i].p_type == PT_INTERP)
		{
			printf("      [Requesting program interpreter: ");
			printf("%s]\n", (char *) (phdr[i].p_offset + p));
		}
	}
	print_segments64(p);
	return (EXIT_SUCCESS);
}

/**
 * print_phdr32 - Generate the output from program headers, 32 bit
 * @p: The first byte of the elf file
 * Return: 0 if success, 1 if no headers
*/

int print_phdr32(char *p)
{
	Elf32_Ehdr *ehdr = (Elf32_Ehdr *)p;
	Elf32_Phdr *phdr = (Elf32_Phdr *)(p + ehdr->e_phoff);
	Elf32_Off phoff = ehdr->e_phoff;
	int phnum = ehdr->e_phnum;
	int i = 0;
	char phtype[4] = "   \0";

	if (phnum == 0)
	{
		printf("\nThere are no program headers in this file.\n");
		return (EXIT_FAILURE);
	}

	printf("\nElf file type is %s\n", etype_to_str32(ehdr->e_type));
	printf("Entry point 0x%x\nThere are ", ehdr->e_entry);
	printf("%d program headers, starting at offset %d", phnum, phoff);
	printf("\n\nProgram Headers:\n  Type           Offset   VirtAddr");
	printf("   PhysAddr   FileSiz MemSiz  Flg Align\n");
	for (i = 0; i < phnum; ++i)
	{
		printf("  %-13s  ", phtype_to_str32(phdr[i].p_type));
		printf("0x%06x ", phdr[i].p_offset);
		printf("0x%08x ", phdr[i].p_vaddr);
		printf("0x%08x ", phdr[i].p_paddr);
		printf("0x%05x ", phdr[i].p_filesz);
		printf("0x%05x ", phdr[i].p_memsz);
		printf("%s ", phflag_to_str32(phdr[i].p_flags, phtype));
		if (phdr[i].p_align == 0)
			printf("0");
		else
			printf("0x%x", phdr[i].p_align);
		printf("\n");
		if (phdr[i].p_type == PT_INTERP)
		{
			printf("      [Requesting program interpreter: ");
			printf("%s]\n", (char *) (phdr[i].p_offset + p));
		}
	}
	print_segments32(p);
	return (EXIT_SUCCESS);
}
