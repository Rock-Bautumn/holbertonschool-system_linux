#include "task2.h"

/**
 * etype_to_str64 - Find the string output for a given elf type, 64 bit
 * @etype: the elf type from ehdr
 * Return: The string of the etype
*/

char *etype_to_str64(Elf64_Half etype)
{
	if (etype == ET_CORE)
		return ("CORE (Core file)");
	else if (etype == ET_EXEC)
		return ("EXEC (Executable file)");
	else if (etype == ET_REL)
		return ("REL (Relocatable file)");
	else if (etype == ET_DYN)
		return ("DYN (Shared object file)");
	else if (etype == ET_NONE)
		return ("Unknown type");
	else
		return ("Something weird");
}

/**
 * etype_to_str32 - Find the string output for a given elf type, 32 bit
 * @etype: the elf type from ehdr
 * Return: The string of the etype
*/

char *etype_to_str32(Elf32_Half etype)
{
	if (etype == ET_CORE)
		return ("CORE (Core file)");
	else if (etype == ET_EXEC)
		return ("EXEC (Executable file)");
	else if (etype == ET_REL)
		return ("REL (Relocatable file)");
	else if (etype == ET_DYN)
		return ("DYN (Shared object file)");
	else if (etype == ET_NONE)
		return ("Unknown type");
	else
		return ("Something weird");
}

/**
 * phtype_to_str64 - Find the string output for a given program header type
 * @phtype: the program header type from phdr, 64 bits
 * Return: The string of the phtype
*/


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

/**
 * phtype_to_str32 - Find the string output for a given program header type
 * @phtype: the program header type from phdr, 32 bits
 * Return: The string of the phtype
*/

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

/**
 * phflag_to_str64 - Generate the output string of phflags
 * @phflag: the program header flag from phdr, 64 bits
 * @phtype: the output string address
 * Return: The string of the phflag
*/

char *phflag_to_str64(Elf64_Word phflag, char *phtype)
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
