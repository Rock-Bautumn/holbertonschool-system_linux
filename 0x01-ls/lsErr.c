#include "main.h"

void lsErr(parsedCmdLine *lsArgs, char *description, char *example)
{
    fprintf(stderr, "%s: %s '%s': ", lsArgs->invoker, description, example);
    perror("");
}
