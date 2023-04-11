#include "../server.h"

/**
 * ErrorAndDie - Print an error message with perror and exit with failure
 * @string: The error message to print with perror
 * Return: void
*/
void ErrorAndDie(char *string)
{
	perror(string);
	exit(EXIT_FAILURE);
}
