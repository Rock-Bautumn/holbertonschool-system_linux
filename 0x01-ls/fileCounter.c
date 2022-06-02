#include "main.h"
/* printf("mode_t for this is %i\n", thisStat.st_mode); */
int fileCounter(parsedCmdLine *lsArgs, char **argv, int argc)
{
	int count = 0;
	int i = 1;
	int result = 0;
	struct stat thisStat;

	for (i = 1; i < argc; i++)
	{
		printf("file counting %s\n", argv[i]);
		result = lstat(argv[i], &thisStat);
		if (result < 0)
			lsErr(lsArgs, "cannot access", argv[i]);

		else if (S_ISREG(thisStat.st_mode) == 1)
		{
			count++;
			printf("matched on %s\n", argv[i]);
		}
	}
	return count;
}
