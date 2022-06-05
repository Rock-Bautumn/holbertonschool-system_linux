#include "main.h"

void outputResults(parsedCmdLine *lsArgs)
{
	printf("file qty = %lu\n", lsArgs->fileQty);
	printf("dir qty = %lu\n", lsArgs->dirQty);

	printList(lsArgs->files, lsArgs->fileQty);
	printList(lsArgs->dirs, lsArgs->dirQty);
	printf("Output results is donels!\n");

}
