#include "main.h"

void initArgs(parsedCmdLine *lsArgs, char *invokeStr)
{
    lsArgs->option_a = 0;
    lsArgs->option_A = 0;
    lsArgs->option_l = 0;
    lsArgs->option_one = 0;
    lsArgs->invoker = invokeStr;
    printf("finished initializing the struct.\nprogram is %s\n", lsArgs->invoker);
}