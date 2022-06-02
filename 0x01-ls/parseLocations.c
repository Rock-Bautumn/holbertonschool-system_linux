#include "main.h"

void parseLocations(parsedCmdLine *lsArgs, char **argv, int argc)
{
	size_t foundFiles = fileCounter(lsArgs, argv, argc);
	size_t foundDirs = dirCounter(lsArgs, argv,	argc);

	lsArgs->files = malloc(sizeof(char *) * foundFiles + 1);
	lsArgs->dirs = malloc(sizeof(char *) * foundDirs + 1);	
	free(lsArgs->files);
	free(lsArgs->dirs);
	printf("we found %lu files\n", foundFiles);
	printf("we found %lu dirs\n", foundDirs);
	printf("Parsed locations!\n");
}
