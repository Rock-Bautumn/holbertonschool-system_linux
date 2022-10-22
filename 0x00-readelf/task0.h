#ifndef TASK_0
#define TASK_0
#define SWAP(x) swapBytes(&x, sizeof(x))

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

void doBigEndian(void);
void swapBytes(void *pv, size_t n);
void lineItemPrint(char *label, char *value);
void labelPrint(char *label);
void getOSABI(unsigned char value);
int checkelf(char *ls);
void print_magic_bytes(char *ls);
void print_elf_class(char *ls);
void print_endianness(char *ls);
void print_elf_version(char *ls);
void print_type64(char *ls);
void print_machine64(char *ls);
void print_elf_64bit(char *ls);
void print_type32(char *ls);
void print_machine32(char *ls);

#endif /* TASK_0 */
