#include "main.h"

void checkArg(parsedCmdLine *lsArgs, char arg)
{
	int i;
	argument_t ops[] = {
		{'a', argOpa},
		{'A', argOpA},
		{'l', argOpl},
		{'1', argOp1},
		{'\0', NULL}
	};
    printf("in checkArg before for loop\n");
	for (i = 0; ops[i].triggerArg != '\0'; i++)
    {
        printf("comparing %c to %c ...\n", arg, ops[i].triggerArg);
		if (arg == ops[i].triggerArg)
		{
            printf("matched %c in checkArg!\n", arg);
			ops[i].f(lsArgs, arg);
			return;
		}
    }
	fprintf(stderr, ": unknown argument %c\n", arg);
	exit(EXIT_FAILURE);
}
