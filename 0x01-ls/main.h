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



int mystrcmp(char *s1, char *s2);

void checkArg(parsedCmdLine *lsArgs, char arg);
void insertArgs(parsedCmdLine *lsArgs, char *argv);
void listFiles(const char* dirname);
void parseArgs(parsedCmdLine *lsArgs, char **argv, int argc);
void parseLocations(parsedCmdLine *lsArgs, char **argv, int argc);
void argOpa(parsedCmdLine *theseLSargs, char thisArg);
void argOpA(parsedCmdLine *theseLSargs, char thisArg);
void argOpl(parsedCmdLine *theseLSargs, char thisArg);
void argOp1(parsedCmdLine *theseLSargs, char thisArg);
void outputResults(parsedCmdLine *lsArgs);

#endif /* MAIN_H */
