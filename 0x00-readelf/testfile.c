#include <string.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

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
		printf("  Data:%*s%s", 30, " ", "2's complement, big endian\n");
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
		labelPrint("Entry point address:");
		printf("0x%lx\n", ((Elf64_Ehdr *)ls)->e_entry);
		/* printf("Entry point address: %p\n", (void *)((Elf64_Ehdr *)ls)->e_entry); */
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
		printf("\n");
		labelPrint("Entry point address:");
		printf("0x%x\n",((Elf32_Ehdr *)ls)->e_entry);
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
