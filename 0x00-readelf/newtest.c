#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


char *sht_str64(Elf64_Word shtype)
{
	switch (shtype)
	{
	case SHT_PROGBITS:
		return ("PROGBITS");
	case SHT_DYNSYM:
		return ("DYMSYM");
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
	default:
		break;
	}
	return (NULL);
}

char *sht_str32(Elf32_Word shtype)
{
	switch (shtype)
	{
	case SHT_PROGBITS:
		return ("PROGBITS");
	case SHT_DYNSYM:
		return ("DYMSYM");
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
		break;
	}
	return (NULL);
}

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

	return retval;
}

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
void print_keyflag_legend(void)
{
	printf("Key to Flags:\n  W (write), A (alloc), X (execute), ");
	printf("M (merge), S (strings), l (large)\n  I (info), L ");
	printf("(link order), G (group), T (TLS), E (exclude), x (unknown)\n");
	printf("  O (extra OS processing required) o (OS specific), ");
	printf("p (processor specific)\n");
}

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
		printf("%2ld \n", shdr[i].sh_addralign);
	}
	print_keyflag_legend();
	return 0;
}

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
	printf("  [Nr] Name              Type            Address          ");
	printf("Off    Size   ES Flg Lk Inf Al\n");
	for (i = 0; i < shnum; ++i) {
		memcpy(retval, "\0\0\0\0", 4);
		shtype = shdr[i].sh_type;
		printf("  [%2d] %-17s ", i,
		sh_strtab_p + shdr[i].sh_name);

		printf("%-16s", sht_str32(shtype));
		printf("%016x ", shdr[i].sh_addr);
		printf("%06x ", shdr[i].sh_offset);
		printf("%06x ", shdr[i].sh_size);
		printf("%02x ", shdr[i].sh_entsize);
		printf("%3s ", flg_to_str32(retval, shdr[i].sh_flags));
		printf("%2d ", shdr[i].sh_link);
		printf("%3d ", shdr[i].sh_info);
		printf("%2d \n", shdr[i].sh_addralign);
	}
	print_keyflag_legend();
	return 0;
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
		print_shdr64(p);
	else if ((unsigned char)p[EI_CLASS] == ELFCLASS32)
		print_shdr32(p);
	else
		printf("Class:%*s", 35, "Invalid class\n");


	return (EXIT_SUCCESS);
}
