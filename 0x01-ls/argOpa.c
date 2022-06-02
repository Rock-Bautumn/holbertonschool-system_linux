#include "main.h"

void argOpa(parsedCmdLine *theseLSargs, char thisArg)
{
    (void) thisArg;
    printf("ArgOpa triggered!\n");
    theseLSargs->option_A = 0;
    theseLSargs->option_a = 1;
}