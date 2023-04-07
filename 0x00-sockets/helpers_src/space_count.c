#include "../server.h"

/**
 * space_count - Counts the number of buckets to allocate to store the data
 *               when given a string delimiter of the data
 * @str: The string to evaluate
 * @delimiter: The string that is breaking up str
 * Return: The number of spaces to store the data, trailing NULL excluded
 */

int space_count(char *str, char *delimiter)
{
	int i = 0;
	int count = 1;
	int gotspace = 1;
	char delim = delimiter[0];

	if (str[i] == '\0' || str == NULL)
		return (0);

	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			if (gotspace == 0)
			{
				count++;
				gotspace = 1;
			}
		}
		else
			gotspace = 0;
		i++;
	}
	return (count);
}
