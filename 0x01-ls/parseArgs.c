#include "main.h"

void parseArgs(parsedCmdLine lsArgs, char **argv, int argc)
{
	int i;

	(void) lsArgs;
	(void) argv;
	(void) argc;
	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-')
			insertArgs(lsArgs, argv[i]);
	}
	printf("Parsed arguments!\n");
}
