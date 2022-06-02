#ifndef MAIN_H
#define MAIN_H

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


typedef struct parsedCommandLine {
    char option_a;
    char option_A;
    char option_l;
    char option_one;
    char **files;
    char **dirs;
    char *invoker;
} parsedCmdLine;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct argument_s
{
	char triggerArg;
	void (*f)(parsedCmdLine *theseLSargs, char thisArg);
} argument_t;

int lstat(const char *pathname, struct stat *statbuf);
int dirCounter(parsedCmdLine *lsArgs, char **argv, int argc);
int fileCounter(parsedCmdLine *lsArgs, char **argv, int argc);
int mystrcmp(char *s1, char *s2);

void checkArg(parsedCmdLine *lsArgs, char arg);
void initArgs(parsedCmdLine *lsArgs, char *invokeStr);

void insertArgs(parsedCmdLine *lsArgs, char *argv);
void listFiles(parsedCmdLine *lsArgs, char* dirname);
void lsErr(parsedCmdLine *lsArgs, char *description, char *thisCase);
void parseArgs(parsedCmdLine *lsArgs, char **argv, int argc);
void parseLocations(parsedCmdLine *lsArgs, char **argv, int argc);
void argOpa(parsedCmdLine *theseLSargs, char thisArg);
void argOpA(parsedCmdLine *theseLSargs, char thisArg);
void argOpl(parsedCmdLine *theseLSargs, char thisArg);
void argOp1(parsedCmdLine *theseLSargs, char thisArg);
void outputResults(parsedCmdLine *lsArgs);

#endif /* MAIN_H */
