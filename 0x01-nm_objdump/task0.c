#include "task0.h"


/**
 * print_shdr32 - Generate the output of the section headers
 * @p: The first byte of the elf file
 * Return: always 0
*/

int print_shdr32(char *p)
{
	Elf32_Ehdr *ehdr = (Elf32_Ehdr *)p;
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
	for (i = 0; i < shnum; ++i)
	{
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
		if (strcmp(sh_strtab_p + shdr[i].sh_name, ".symtab") == 0)
		{
			printf("found symtab\n");

		}
	}
	print_keyflag_legend32();
	return (EXIT_SUCCESS);
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
	int *elf;

	if (argc > 1)
		fname = argv[1];

	if (stat(fname, &st) != 0)
	{
		perror("stat");
		return (EXIT_FAILURE);
	}

	fd = open(fname, O_RDONLY);
	p = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	elf = (void *) p;
	if (*elf != 1179403647)
	{
		fprintf(stderr, "Not an ELF file.");
		return (EXIT_FAILURE);
	}
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
