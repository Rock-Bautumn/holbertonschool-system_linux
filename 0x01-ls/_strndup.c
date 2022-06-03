#include "main.h"

/**
 * _strndup - Returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter.
 * @str: the string to copy
 * @max: the maximum number of characters to copy
 * Return: the address of the copied string, NULL if failed
 */

char *_strndup(char *str, int maxlen)
{
	int x = 0;
	int size = 0;
	char *newString;

	if (str == NULL)
		return (NULL);

	size  = _strnlen(str, maxlen);
	newString = malloc(size * sizeof(char) + 1);

	if (newString == NULL)
		return (NULL);

	while (x < size)
	{
		*(newString + x) = *(str + x);
		x++;
	}
	*(newString + x) = '\0';
	return (newString);
}
