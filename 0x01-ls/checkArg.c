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
	fprintf(stderr, "%s: invalid option -- \'%c\'\n", lsArgs->invoker, arg);
	fprintf(stderr, "Try '%s --help' for more information.", lsArgs->invoker);
	fprintf(stderr, "\n");
	exit(EXIT_FAILURE);
}
