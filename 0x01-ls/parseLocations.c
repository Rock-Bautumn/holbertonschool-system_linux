#include "main.h"

void parseLocations(parsedCmdLine *lsArgs, char **argv, int argc)
{

	size_t foundFiles = fileCounter(lsArgs, argv, argc);
	size_t foundDirs = dirCounter(lsArgs, argv, argc);

	lsArgs->fileQty = foundFiles;
	lsArgs->dirQty = foundDirs;

	lsArgs->files = fileListMalloc(lsArgs);
	lsArgs->dirs = dirListMalloc(lsArgs);

	if (foundDirs == 0 && foundFiles == 0)
	{
		printf("found no file or dir args\n");
		lsArgs->dirs[0] = _strndup(".", 1);
		lsArgs->dirQty = 1;
		printf("first dir is %s\n", lsArgs->dirs[0]);
	}


	printf("we found %lu files\n", foundFiles);
	printf("we found %lu dirs\n", foundDirs);
	printf("saved into lsArgs:\n");
	printf("we saved %lu fileQty\n", lsArgs->fileQty);
	printf("we saved %lu dirQty\n", lsArgs->dirQty);

	addItemsToLists(lsArgs, argv, argc);

	printf("Parsed locations!\n");
}
/*
	free(lsArgs->files);
	free(lsArgs->dirs[0]);
	free(lsArgs->dirs);
	*/
