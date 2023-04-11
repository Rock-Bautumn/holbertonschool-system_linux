#include "../server.h"

/**
 * char_occurrences - Count the number of times a character appears in a string
 * @string: The string to look through
 * @chr: The character to look for and count in the string
 * Return: The quantity of occurrences of the character in the string
*/
size_t char_occurrences(char *string, char chr)
{
	size_t count = 0, check_pos = 0;

	for (; string[check_pos]; check_pos++)
		if (string[check_pos] == chr)
			count++;

	return (count);
}
