#ifndef GETLINE_H
#define GETLINE_H
#define READ_SIZE (5)
#define DOUBLE_READ_SIZE (READ_SIZE * 2)

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

char *_getline(const int fd);
void print_mem(char *first_byte, int length);

#endif
