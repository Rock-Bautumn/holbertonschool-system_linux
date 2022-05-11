#ifndef MAIN_H
#define MAIN_H

#include <dirent.h>
#include <stdio.h>
#include <string.h>

typedef struct parsedCommandLine {
    char option_a;
    char option_A;
    char option_l;
    char option_one;
    char **items;
} parsedCmdLine;

void listFiles(const char* dirname);
int _strcmp(char *s1, char *s2);



#endif
