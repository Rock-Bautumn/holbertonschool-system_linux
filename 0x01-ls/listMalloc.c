#include "main.h"


char **listMalloc(parsedCmdLine *lsArgs, size_t size, char dirMode, char **addlFree)
{
	char **returnList;
	char **holder;

	if (size == 0 && dirMode == 1)
		holder = malloc(sizeof(char *) * 1);
	else if (size == 0)
		return NULL;
	holder = malloc(sizeof(char *) * size);
	if (holder == NULL)
	{
		if (addlFree == NULL)
			lsErr(lsArgs, "out of memory", "malloc for files");
		else
		{
			lsErr(lsArgs, "out of memory", "malloc for dirs");
			free(addlFree);
		}
		exit(EXIT_FAILURE);
	}
	returnList = holder;
	return returnList;
}
