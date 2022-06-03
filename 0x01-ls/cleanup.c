#include "main.h"

void cleanup(parsedCmdLine *lsArgs)
{

	freeList(lsArgs->dirs, lsArgs->fileQty);
	freeList(lsArgs->files, lsArgs->dirQty);
}
