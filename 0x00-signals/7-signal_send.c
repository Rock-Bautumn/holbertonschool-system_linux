#include "signals.h"

/**
 * main - Send interrupt signal to process ID
 * @ac: The number of arguments
 * @av: The argument vector
 * Return: 0 on success
*/
int main(int ac, char **av)
{
	int pid;

	if (ac < 2)
	{
		printf("Usage: %s <pid>\n", av[0]);
		return (EXIT_FAILURE);
	}
	pid = atoi(av[1]);
	return (kill(pid, SIGINT));
}
