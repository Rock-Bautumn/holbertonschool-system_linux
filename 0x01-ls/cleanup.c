#include "main.h"

void cleanup(parsedCmdLine *lsArgs)
{
	printf("beginning cleanup\n");
	fflush(NULL);
	freeList(lsArgs->dirs, lsArgs->dirQty);
	printf("cleaning up dirs\n");
	freeList(lsArgs->files, lsArgs->fileQty);
	printf("cleanup is done\n");
}
