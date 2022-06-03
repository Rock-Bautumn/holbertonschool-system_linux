#include "main.h"


char **listMalloc(parsedCmdLine *lsArgs, char dirMode)
{
	char **holder;

	if (dirMode == 1)
	{
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
	}
	else
	{
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
	}
	
	return holder;
}
