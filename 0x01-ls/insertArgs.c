#include "main.h"

void insertArgs(parsedCmdLine *lsArgs, char *argv)
{
	int i = 1;

	(void) lsArgs;
	while (argv[i] != '\0')
	{
		printf("Grabbed char %c\n", argv[i]);
		checkArg(lsArgs, argv[i]);
		i++;
	}
}
