#include "main.h"


char **dirListMalloc(parsedCmdLine *lsArgs)
{
	char **holder;

	if (lsArgs->dirQty == 0 && lsArgs->fileQty == 0)
	{
		holder = malloc(sizeof(char *));
		if (holder == NULL)
		{
			lsErr(lsArgs, "out of memory", "malloc4dirs");
			free(lsArgs->files);
			exit(EXIT_FAILURE);
		}
	}
	else if (lsArgs->dirQty > 0)
	{
		holder = malloc(sizeof(char *) * lsArgs->dirQty);
		if (holder == NULL)
		{
			lsErr(lsArgs, "out of memory", "malloc4dirs");
			free(lsArgs->files);
			exit(EXIT_FAILURE);
		}
	}
	else
		return NULL;

	return holder;
}
