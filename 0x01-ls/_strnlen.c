#include "main.h"

/**
 * _strnlen - returns the length of a string
 *
 * @s: the string we are counting the characters of
 * @max: the maximum number of characters to count
 * Return: the length of the string
 */
int _strnlen(char *s, int max)
{
	int length = 0;

	if (max < 0)
		max = INT_MAX;
	while (*s != '\0' && length < max)
	{
		s++;
		length++;
	}
	return (length);
}
