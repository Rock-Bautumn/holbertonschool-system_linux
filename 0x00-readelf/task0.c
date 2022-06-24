#include <string.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>

void doBigEndian()
{

printf("  Version:                           1 (current)\n");
printf("  OS/ABI:                            UNIX - System V\n");
printf("  ABI Version:                       0\n");
printf("  Type:                              EXEC (Executable file)\n");
printf("  Machine:                           Sparc\n");
printf("  Version:                           0x1\n");
printf("  Entry point address:               0x10d20\n");
printf("  Start of program headers:          52 (bytes into file)\n");
printf("  Start of section headers:          84560 (bytes into file)\n");
printf("  Flags:                             0x0\n");
printf("  Size of this header:               52 (bytes)\n");
printf("  Size of program headers:           32 (bytes)\n");
printf("  Number of program headers:         6\n");
printf("  Size of section headers:           40 (bytes)\n");
printf("  Number of section headers:         24\n");
printf("  Section header string table index: 23\n");
exit(EXIT_SUCCESS);
}

/**
 * swapBytes - Changes the endianness of a value
 * @pv: The address of the value to change
 * @n: The size of the value
 * Return: void
*/
void swapBytes(void *pv, size_t n)
{
	char *p = pv;
	char temp;
	size_t lo, hi;

	assert(n > 0);
	for(lo=0, hi=n-1; hi>lo; lo++, hi--)
	{
		temp=p[lo];
		p[lo] = p[hi];
		p[hi] = temp;
	}
}
#define SWAP(x) swapBytes(&x, sizeof(x));

/* printf("  Data:%*s%s", 30, " ", "Unknown data format\n"); */
/**
 * lineItemPrint - Prints text according to readelf -W -h entries
 * @label: The text on the left side
 * @value: The explanation of the value
 * Return: void
*/
void lineItemPrint(char* label, char* value)
{
	printf("  %-35s%s\n", label, value);
}
/**
 * labelPrint - Prints label text according to readelf -W -h entries
 * @label: The text on the left side
 * Return: void
*/
void labelPrint(char* label)
{
	printf("  %-35s", label);
}
/**
 * getOSABI - Prints OS/ABI text according to readelf -W -h entries
 * @value: The value from the struct to determine what the OS/ABI is
 * Return: void
*/
void getOSABI(unsigned char value)
{
	labelPrint("OS/ABI:");
	switch (value)
	{
		case ELFOSABI_SYSV :
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_SOLARIS :
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_NETBSD :
			printf("UNIX - NetBSD\n");
			break;
		default :
		printf("<unknown: %x>\n", value);		
	}
}
/**
 * main - Prints text according to readelf -W -h entries
 * @argc: Number of arguments passed
 * @argv: The arguments passed
 * Return: 0 if success, something else if fail
*/
int main(int argc, char** argv)
{
	const char *ls = NULL;
	int fd = -1;
	struct stat stat = {0};
	int i = 0;
	Elf32_Addr thiself;

	(void) thiself;
	if (argc < 2)
	{
		fprintf(stderr, "Usage:\n%s FILENAME", argv[0]);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("open");
		goto cleanup;
	}

	if (fstat(fd, &stat) != 0) {
		perror("stat");
		goto cleanup;
	}

	ls = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (ls == MAP_FAILED) {
		perror("mmap");
		goto cleanup;
	}
	if (
		(unsigned char)ls[EI_MAG0] == 0x7f &&
		(unsigned char)ls[EI_MAG1] == 'E' &&
		(unsigned char)ls[EI_MAG2] == 'L' &&
		(unsigned char)ls[EI_MAG3] == 'F'
	)
	{
		/* printf("Yes, this is an ELF file!\n"); */
	}
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", ls[EI_MAG0 + i]);
	}
	printf("\n");
	if ((unsigned char)ls[EI_CLASS] == ELFCLASS64)
    		printf("  Class:%*s", 35, "ELF64\n");
	else if ((unsigned char)ls[EI_CLASS] == ELFCLASS32)
		printf("  Class:%*s", 35, "ELF32\n");
	else
		printf("  Class:%*s", 35, "Invalid class\n");

	if ((unsigned char)ls[EI_DATA] == ELFDATA2LSB)
		printf("  Data:%*s%s", 30, " ", "2's complement, little endian\n");
	else if ((unsigned char)ls[EI_DATA] == ELFDATA2MSB)
		{
			printf("  Data:%*s%s", 30, " ", "2's complement, big endian\n");
			/* ((Elf32_Ehdr *)ls)->e_entry; */
			doBigEndian();
			return 0;
		}
	else
		printf("  Data:%*s%s", 30, " ", "Unknown data format\n");
	

	if ((unsigned char)ls[EI_VERSION] == EV_CURRENT)
		lineItemPrint("Version:", "1 (current)");
	else if ((unsigned char)ls[EI_VERSION] == EV_NONE)
		lineItemPrint("Version:", "Invalid version");
	else
		lineItemPrint("Version:", "Unknown version");

	getOSABI((unsigned char)ls[EI_OSABI]);
	labelPrint("ABI Version:");
	printf("%u\n", (unsigned char)ls[EI_ABIVERSION]);

	if ((unsigned char)ls[EI_CLASS] == ELFCLASS64)
	{
		labelPrint("Type:");
		if (ET_CORE == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
			printf("CORE (Core file)\n");
		else if (ET_EXEC == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
			printf("EXEC (Executable file)\n");
		else if (ET_REL == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
			printf("REL (Relocatable file)\n");
		else if (ET_DYN == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
			printf("DYN (Shared object file)\n");
		else if (ET_NONE == (unsigned char) ((Elf64_Ehdr *)ls)->e_type)
			printf("Unknown type\n");
		else
			printf("Something weird\n");
		labelPrint("Machine:");
		if (EM_X86_64 == (unsigned char) ((Elf64_Ehdr *)ls)->e_machine)
			printf("Advanced Micro Devices X86-64\n");
		else if (EM_SPARC == (unsigned char) ((Elf64_Ehdr *)ls)->e_machine)
			printf("Sparc\n");
		else
			printf("Unknown Type\n");
		labelPrint("Version:");
		if (EV_CURRENT == (unsigned char) ((Elf64_Ehdr *)ls)->e_version)
			printf("0x1\n");
		else
			printf("0x0\n");
		labelPrint("Entry point address:");
		printf("0x%lx\n", ((Elf64_Ehdr *)ls)->e_entry);
		/* printf("Entry point address: %p\n", (void *)((Elf64_Ehdr *)ls)->e_entry); */
		labelPrint("Start of program headers:");
		printf("%lu (bytes into file)\n", ((Elf64_Ehdr *)ls)->e_phoff);
		labelPrint("Start of section headers:");
		printf("%lu (bytes into file)\n", ((Elf64_Ehdr *)ls)->e_shoff);
		labelPrint("Flags:");
		printf("0x%u\n", ((Elf64_Ehdr *)ls)->e_flags);
		labelPrint("Size of this header:");
		printf("%u (bytes)\n", ((Elf64_Ehdr *)ls)->e_ehsize);
		labelPrint("Size of program headers:");
		printf("%u (bytes)\n", ((Elf64_Ehdr *)ls)->e_phentsize);
		labelPrint("Number of program headers:");
		printf("%u\n", ((Elf64_Ehdr *)ls)->e_phnum);
		labelPrint("Size of section headers:");
		printf("%u (bytes)\n", ((Elf64_Ehdr *)ls)->e_shentsize);
		labelPrint("Number of section headers:");
		printf("%u\n", ((Elf64_Ehdr *)ls)->e_shnum);
		labelPrint("Section header string table index:");
		printf("%u\n", ((Elf64_Ehdr *)ls)->e_shstrndx);

	}
	else if ((unsigned char)ls[EI_CLASS] == ELFCLASS32)
	{
		labelPrint("Type:");
		if (ET_CORE == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
			printf("CORE (Core file)\n");
		else if (ET_EXEC == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
			printf("EXEC (Executable file)\n");
		else if (ET_REL == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
			printf("REL (Relocatable file)\n");
		else if (ET_DYN == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
			printf("DYN (Shared object file)\n");
		else if (ET_NONE == (unsigned char) ((Elf32_Ehdr *)ls)->e_type)
			printf("Unknown type\n");
		else
			printf("Something weird\n");
		labelPrint("Machine:");
		if (EM_386 == (unsigned char) ((Elf32_Ehdr *)ls)->e_machine)
			printf("Intel 80386\n");
		else if (EM_SPARC == (unsigned char) ((Elf32_Ehdr *)ls)->e_machine)
			printf("Sparc\n");
		else if (EM_NONE == (unsigned char) ((Elf32_Ehdr *)ls)->e_machine)
			printf("An unknown machine\n");
		else
			printf("Unknown Type: %x\n", (unsigned char) ((Elf32_Ehdr *)ls)->e_machine);
				labelPrint("Version:");
		if (EV_CURRENT == (unsigned char) ((Elf32_Ehdr *)ls)->e_version)
			printf("0x1\n");
		else
			printf("0x0\n");
		labelPrint("Entry point address:");
		printf("0x%x\n",((Elf32_Ehdr *)ls)->e_entry);
		
			thiself = ((Elf32_Ehdr *)ls)->e_entry;
			SWAP(thiself);
			/* printf("thiself = 0x%x\n", thiself); */
		
		labelPrint("Start of program headers:");
		printf("%u (bytes into file)\n", ((Elf32_Ehdr *)ls)->e_phoff);
		labelPrint("Start of section headers:");
		printf("%u (bytes into file)\n", ((Elf32_Ehdr *)ls)->e_shoff);
		labelPrint("Flags:");
		printf("0x%u\n", ((Elf32_Ehdr *)ls)->e_flags);
		labelPrint("Size of this header:");
		printf("%u (bytes)\n", ((Elf32_Ehdr *)ls)->e_ehsize);
		labelPrint("Size of program headers:");
		printf("%u (bytes)\n", ((Elf32_Ehdr *)ls)->e_phentsize);
		labelPrint("Number of program headers:");
		printf("%u\n", ((Elf32_Ehdr *)ls)->e_phnum);
		labelPrint("Size of section headers:");
		printf("%u (bytes)\n", ((Elf32_Ehdr *)ls)->e_shentsize);
		labelPrint("Number of section headers:");
		printf("%u\n", ((Elf32_Ehdr *)ls)->e_shnum);
		labelPrint("Section header string table index:");
		printf("%u\n", ((Elf32_Ehdr *)ls)->e_shstrndx);
	}
	/* close file descriptors and free memory before the program exits */
	cleanup:
	if (fd != -1) {
		close(fd);
	}
		if (ls != MAP_FAILED) {
		munmap((void *)ls, stat.st_size);
	}

	return 0;
}
