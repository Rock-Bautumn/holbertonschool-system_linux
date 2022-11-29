#ifndef TASK_0
#define TASK_0

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

#include "shtypes.h"

char *sht_str32(Elf32_Word shtype);
char *sht_str32II(Elf32_Word shtype);
char *sht_str64(Elf64_Word shtype);
void dosparcbigendian32(void);
void dosparcbigendian32II(void);

char *flg_to_str64(char *retval, Elf64_Xword flags);
char *flg_to_str32(char *retval, Elf32_Xword flags);
void print_keyflag_legend64(void);
void print_keyflag_legend32(void);
int print_shdr64(char *p);

#endif /* TASK_0 */
