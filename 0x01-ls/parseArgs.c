#include "main.h"

void parseArgs(parsedCmdLine *lsArgs, char **argv, int argc)
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
	printf("Parsed arguments!\nThey contain:");
	printf("option a: %d\n", lsArgs->option_a);
	printf("option A: %d\n", lsArgs->option_A);
	printf("option l: %d\n", lsArgs->option_l);
	printf("option 1: %d\n", lsArgs->option_one);
	
}