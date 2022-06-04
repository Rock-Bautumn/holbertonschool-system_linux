#include "main.h"


char **fileListMalloc(parsedCmdLine *lsArgs)
{
	char **holder;

	if (lsArgs->fileQty < 1)
		return NULL;
	else
	{
		holder = malloc(sizeof(char *) * lsArgs->fileQty);
		if (holder == NULL)
		{
			lsErr(lsArgs, "out of memory", "malloc4files");
			exit(EXIT_FAILURE);
		}
	}

	return holder;
}
