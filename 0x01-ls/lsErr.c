#include "main.h"

void lsErr(parsedCmdLine *lsArgs, char *description, char *thisCase)
{
    fprintf(stderr, "%s: %s '%s': ", lsArgs->invoker, description, thisCase);
    perror("");
}