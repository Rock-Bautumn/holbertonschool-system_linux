#include "signals.h"

/**
 * current_handler_sigaction - Return the address of the signal handler
 * Return: The address of the signal handler, NULL if not found or error
*/
void (*current_handler_sigaction(void))(int)
{
	int handler;
	struct sigaction oldact;

	handler = sigaction(SIGINT, NULL, &oldact);
	if (handler == -1)
		return (NULL);
	return (oldact.sa_handler);
}
