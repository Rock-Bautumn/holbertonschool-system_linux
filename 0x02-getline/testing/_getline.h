#ifndef GETLINE_H
#define GETLINE_H
#define READ_SIZE (1024)

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *_getline(const int fd);

#endif
