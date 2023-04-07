#include "../server.h"

/**
 * ndsplitter - non-destructive version of splitter(), uses a malloced copy
 * @fun: The string we are splitting up
 * @delimiter: the delimiter to split up the string
 * Return: A list of strings broken up by delimiter
 */

char **ndsplitter(char *fun, char *delimiter)
{
	char **holder;
	int i = 0;
	long int length = space_count(fun, delimiter);
	char *temp;
	char *copyoffun;
	char *grabtok;

	copyoffun = strdup(fun);
/*strtok must take an array of chars not a pointer*/
	holder = malloc(sizeof(char *) * (length + 1));
/*strtok has to be split to the same var so create temp*/
	temp = strdup(strtok(copyoffun, delimiter));
	holder[i] = temp;
	while (temp != NULL)
	{
		i++;
		grabtok = strtok(NULL, delimiter);
		if (grabtok == NULL)
		{
			holder[i] = NULL;
			break;
		}
		temp = strdup(grabtok);
		holder[i] = temp;
	}
	free(copyoffun);
	return (holder);
}
