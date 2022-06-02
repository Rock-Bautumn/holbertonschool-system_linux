#include "main.h"
/* printf("mode_t for this is %i\n", thisStat.st_mode); */
int fileCounter(parsedCmdLine *lsArgs, char **argv, int argc)
{
	int count = 0;
	int i = 1;
	struct stat thisStat;

	for (i = 1; i < argc; i++)
	{
		printf("file counting %s, %c, %d\n", argv[i], argv[i][0], (int) argv[i][0]);
		if (argv[i][0] != '-')		
		{
			printf("%c is not -\n", argv[i][0]);
			if (lstat(argv[i], &thisStat) < 0)
				lsErr(lsArgs, "cannot access", argv[i]);

			else if (S_ISREG(thisStat.st_mode) == 1)
			{
				count++;
				printf("matched on %s\n", argv[i]);
			}
		}
	}
	return count;
}
