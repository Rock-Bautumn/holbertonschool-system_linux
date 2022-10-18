#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <fcntl.h>


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

int print_shdr64(char *p) {
	Elf64_Ehdr *ehdr = (Elf64_Ehdr*)p;
	Elf64_Shdr *shdr = (Elf64_Shdr *)(p + ehdr->e_shoff);
	int shnum = ehdr->e_shnum;
	Elf64_Shdr *sh_strtab = &shdr[ehdr->e_shstrndx];
	const char *const sh_strtab_p = p + sh_strtab->sh_offset;
	Elf64_Word shtype;
	int i = 0;

	printf("There are %d section headers, starting at offset %p:\n",
		shnum, (void *) ehdr->e_shoff);
	printf("\n\nSection Headers:\n");
	printf("  [Nr] Name              Type            Address          ");
	printf("Off    Size   ES Flg Lk Inf Al\n");
	for (i = 0; i < shnum; ++i) {
		shtype = shdr[i].sh_type;
		printf("  [%2d] %-17s ", i,
		sh_strtab_p + shdr[i].sh_name);

		printf("%-16s", sht_str64(shtype));
		printf("000000000");
		printf("\n");
	}

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
		printf("Class:%*s", 35, "ELF32\n");
	else
		printf("  Class:%*s", 35, "Invalid class\n");


	return (EXIT_SUCCESS);
}
