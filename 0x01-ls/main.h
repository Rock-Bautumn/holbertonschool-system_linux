#ifndef MAIN_H
#define MAIN_H

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct parsedCommandLine {
    char option_a;
    char option_A;
    char option_l;
    char option_one;
    char **items;
} parsedCmdLine;

int mystrcmp(char *s1, char *s2);

void insertArgs(parsedCmdLine lsArgs, char *argv);
void listFiles(const char* dirname);
void parseArgs(parsedCmdLine lsArgs, char **argv, int argc);
void parseLocations(parsedCmdLine lsArgs, char **argv, int argc);
void outputResults(parsedCmdLine lsArgs);

#endif /* MAIN_H */
