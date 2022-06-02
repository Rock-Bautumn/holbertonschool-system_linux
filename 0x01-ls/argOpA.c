#include "main.h"

void argOpA(parsedCmdLine *theseLSargs, char thisArg)
{
        (void) theseLSargs;
    (void) thisArg;
    printf("ArgOpA triggered!\n");
    theseLSargs->option_a = 0;
    theseLSargs->option_A = 1;

}