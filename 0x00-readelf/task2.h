#ifndef TASK_2
#define TASK_2

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

char *etype_to_str64(Elf64_Half etype);
char *etype_to_str32(Elf32_Half etype);
char *phtype_to_str64(Elf64_Word phtype);
char *phtype_to_str32(Elf32_Word phtype);
char *phflag_to_str64(Elf64_Word phflag, char *phtype);

int print_phdr32(char *p);
int print_phdr64(char *p);
void print_segments32(char *p);
void print_segments64(char *p);
char *phflag_to_str32(Elf32_Word phflag, char *phtype);


#endif /* TASK_2 */
