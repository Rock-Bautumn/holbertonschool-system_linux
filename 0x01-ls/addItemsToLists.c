#include "main.h"
/* printf("mode_t for this is %i\n", thisStat.st_mode); */
void addItemsToLists(parsedCmdLine *lsArgs, char **argv, int argc)
{
	int filePos = 0;
	int dirPos = 0;
	int i = 1;
	char *temp;
	struct stat thisStat;

	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] != '-')
		{
			printf("%c is not -\n", argv[i][0]);
			if (lstat(argv[i], &thisStat) < 0)
				;

			else if (S_ISDIR(thisStat.st_mode) == 1)
			{
				printf("matched on %s\n", argv[i]);
				temp = _strndup(argv[i], FILENAME_MAX);
				lsArgs->dirs[dirPos] = temp;
				printf("wrote to address %p\n", temp);
				dirPos++;

			}
			else if (S_ISREG(thisStat.st_mode) == 1)
			{
				printf("matched on %s\n", argv[i]);
				temp = _strndup(argv[i], FILENAME_MAX);
				lsArgs->files[filePos] = temp;
				filePos++;
				printf("wrote to address %p\n", temp);

			}
		}
	}
}
