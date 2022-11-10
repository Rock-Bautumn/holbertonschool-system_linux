#include "signals.h"

/**
 * print_gotcha - print a message that a signal was received
 * @sig: the signal
 * Return: void
*/
void print_gotcha(int sig)
{
	printf("Gotcha! [%d]\n", sig);
}

/**
 * handle_sigaction - register a handler for an interrupt signal
 * Return: 0 if success
*/
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = &print_gotcha;
	sa.sa_flags = SA_RESTART;

	return (sigaction(SIGINT, &sa, NULL));
}
