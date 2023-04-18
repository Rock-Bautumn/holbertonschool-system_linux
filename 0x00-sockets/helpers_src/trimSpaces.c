#include "../server.h"

/**
 * trimSpaces - Remove the leading and trailing spaces from a string
 * This function keeps the address of the string the same, so IT IS SAFE to
 * free() this string if it was allocated using malloc()!
 * @string: The string to trim the leading and trailing spaces from
 * Return: void
*/

char *trimSpaces(char *string)
{
	size_t length, pos = 0, swap = 0;

	if (string == NULL)
		return (NULL);

	length = strlen(string);

	for (; string[pos] == ' '; pos++)
		;

	for (; pos < length; string[swap++] = string[pos++])
		;

	string[swap] = '\0';
	length = strlen(string);
	pos = length - 1;

	for (; string[pos] == ' '; pos--)
		;

	string[pos + 1] = '\0';

	return (string);
}
