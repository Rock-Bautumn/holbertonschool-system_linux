#include "signals.h"

/**
 * main - print a message about the signal number
 * @argc: the number of arguments
 * @av: The arguments
 * Return: EXIT_SUCCESS
*/
int main(int argc, char **av)
{
	if (argc < 2)
	{
		printf("Usage: %s <signum>\n", av[0]);
		return (EXIT_FAILURE);
	}
	printf("%s: %s\n", av[1], strsignal(atoi(av[1])));
	return (EXIT_SUCCESS);
}
