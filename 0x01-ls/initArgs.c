#include "main.h"

void initArgs(parsedCmdLine *lsArgs, char *invokeStr)
{
    lsArgs->option_a = 0;
    lsArgs->option_A = 0;
    lsArgs->option_l = 0;
    lsArgs->option_one = 0;
    lsArgs->invoker = invokeStr;
    lsArgs->fileQty = 0;
    lsArgs->dirQty = 0;
    printf("finished initializing the struct.\nprogram is %s\n", lsArgs->invoker);
}
