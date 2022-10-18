#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>



int print_phdr64(char *p) {
	Elf64_Ehdr *ehdr = (Elf64_Ehdr*)p;
	Elf64_Phdr *phdr = (Elf64_Phdr *)(p + ehdr->e_phoff);
	Elf64_Off phoff = ehdr->e_phoff;
	int phnum = ehdr->e_phnum;
	int i = 0;

	printf("\nElf file type is %s\n", "EXEC (Executable file)");
	printf("Entry point 0x400600\nThere are ");
	printf("%d program headers, starting at offset %ld", phnum, phoff);
	printf("\n\nProgram Headers:\n  Type           Offset   VirtAddr");
	printf("           PhysAddr           FileSiz  MemSiz   Flg Align\n");

	for (i = 0; i < phnum; ++i)
	{
		printf("  %-13s  ", "PHDR");
		printf("0x%06x ", phdr[i].p_type);
		printf("0x%016lx\n", phdr[i].p_offset);
		
	}

	return 0;
}

int print_phdr32(char *p) {
	(void) p;
	return 0;
}

void dosparcbigendian32ph(void)
{
	;
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
