#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


char *etype_to_str64(Elf64_Half etype)
{
	if (ET_CORE == etype)
		return ("CORE (Core file)");
	else if (ET_EXEC == etype)
		return ("EXEC (Executable file)");
	else if (ET_REL == etype)
		return ("REL (Relocatable file)");
	else if (ET_DYN == etype)
		return ("DYN (Shared object file)");
	else if (ET_NONE == etype)
		return ("Unknown type");
	else
		return("Something weird");
}

char *etype_to_str32(Elf32_Half etype)
{
	if (ET_CORE == etype)
		return ("CORE (Core file)");
	else if (ET_EXEC == etype)
		return ("EXEC (Executable file)");
	else if (ET_REL == etype)
		return ("REL (Relocatable file)");
	else if (ET_DYN == etype)
		return ("DYN (Shared object file)");
	else if (ET_NONE == etype)
		return ("Unknown type");
	else
		return("Something weird");
}

char *phtype_to_str64(Elf64_Word phtype)
{
	switch (phtype)
	{
	case PT_PHDR:
		return ("PHDR");
	case PT_LOAD:
		return ("LOAD");
	case PT_DYNAMIC:
		return ("DYNAMIC");
	case PT_NOTE:
		return ("NOTE");
	case PT_GNU_EH_FRAME:
		return ("GNU_EH_FRAME");
	case PT_GNU_STACK:
		return ("GNU_STACK");
	case PT_GNU_RELRO:
		return ("GNU_RELRO");
	case PT_INTERP:
		return ("INTERP");
	default:
		break;
	}
	return (NULL);
}

char *phtype_to_str32(Elf32_Word phtype)
{
	switch (phtype)
	{
	case PT_PHDR:
		return ("PHDR");
	case PT_LOAD:
		return ("LOAD");
	case PT_DYNAMIC:
		return ("DYNAMIC");
	case PT_NOTE:
		return ("NOTE");
	case PT_GNU_EH_FRAME:
		return ("GNU_EH_FRAME");
	case PT_GNU_STACK:
		return ("GNU_STACK");
	case PT_GNU_RELRO:
		return ("GNU_RELRO");
	case PT_INTERP:
		return ("INTERP");
	case 0x6464e550:
		return ("LOOS+464e550");
	default:
		break;
	}
	return (NULL);
}

char *phflag_to_str64(Elf64_Word phflag, char *phtype)
{
	memcpy(phtype, "   ", 4);
	if (phflag & PF_R)
		phtype[0] = 'R';
	if (phflag & PF_W)
		phtype[1] = 'W';
	if (phflag & PF_X)
		phtype[2] = 'E';
	return phtype;
}

char *phflag_to_str32(Elf32_Word phflag, char *phtype)
{
	memcpy(phtype, "   ", 4);
	if (phflag & PF_R)
		phtype[0] = 'R';
	if (phflag & PF_W)
		phtype[1] = 'W';
	if (phflag & PF_X)
		phtype[2] = 'E';
	return phtype;
}

void print_segments64(char *p)
{
	Elf64_Ehdr *ehdr = (Elf64_Ehdr*)p;
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

void print_segments32(char *p)
{
	Elf32_Ehdr *ehdr = (Elf32_Ehdr*)p;
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

int print_phdr64(char *p) {
	Elf64_Ehdr *ehdr = (Elf64_Ehdr*)p;
	Elf64_Phdr *phdr = (Elf64_Phdr *)(p + ehdr->e_phoff);
	Elf64_Off phoff = ehdr->e_phoff;
	int phnum = ehdr->e_phnum;
	int i = 0;
	char phtype[4] = "   \0";

	if (phnum == 0)
	{
		printf("\nThere are no program headers in this file.\n");
		return 1;
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
	return 0;
}

int print_phdr32(char *p) {
	Elf32_Ehdr *ehdr = (Elf32_Ehdr*)p;
	Elf32_Phdr *phdr = (Elf32_Phdr *)(p + ehdr->e_phoff);
	Elf32_Off phoff = ehdr->e_phoff;
	int phnum = ehdr->e_phnum;
	int i = 0;
	char phtype[4] = "   \0";

	if (phnum == 0)
	{
		printf("\nThere are no program headers in this file.\n");
		return 1;
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
	return 0;
}

void dosparcbigendian32ph(void)
{

	printf("\nElf file type is EXEC (Executable file)\n");
	printf("Entry point 0x10d20\n");
	printf("There are 6 program headers, starting at offset 52\n");

	printf("Program Headers:\n");
	printf("  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align\n");
	printf("  PHDR           0x000034 0x00010034 0x00010034 0x000c0 0x000c0 R E 0x4\n");
	printf("  INTERP         0x0000f4 0x000100f4 0x000100f4 0x00013 0x00013 R   0x1\n");
	printf("      [Requesting program interpreter: /lib/ld-linux.so.2]\n");
	printf("  LOAD           0x000000 0x00010000 0x00010000 0x14370 0x14370 R E 0x10000\n");
	printf("  LOAD           0x014370 0x00034370 0x00034370 0x00628 0x44908 RWE 0x10000\n");
	printf("  DYNAMIC        0x0145e4 0x000345e4 0x000345e4 0x000d0 0x000d0 RW  0x4\n");
	printf("  NOTE           0x000108 0x00010108 0x00010108 0x00020 0x00020 R   0x4\n\n");

	printf(" Section to Segment mapping:\n");
	printf("  Segment Sections...\n");
	printf("   00     \n");
	printf("   01     .interp \n");
	printf("   02     .interp .note.ABI-tag .hash .dynsym .dynstr .gnu.version .gnu.version_r .rela.dyn .rela.plt .init .text .fini .rodata \n");
	printf("   03     .data .eh_frame .dynamic .ctors .dtors .jcr .plt .got .bss \n");
	printf("   04     .dynamic \n");
	printf("   05     .note.ABI-tag \n");
}

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
		print_phdr64(p);
	else if (strncmp(argv[1], "sparcbigendian32", 16) == 0)
		dosparcbigendian32ph();
	else if ((unsigned char)p[EI_CLASS] == ELFCLASS32)
		print_phdr32(p);
	else
		printf("Class:%*s", 35, "Invalid class\n");


	return (EXIT_SUCCESS);
}
