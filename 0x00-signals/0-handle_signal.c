#include "signals.h"


/**
 *  handle_sigint - Action function for the interrupt signal handler
 * @sig: The signal number received
 * Return: void
*/
void handle_sigint(int sig)
{
	printf("Gotcha! [%d]\n", sig);
}

/**
 * handle_signal - Create a signal jandler for SIG_INT so that it uses
 *                  handle_sigint.
 * Return: 0 if success, -1 if error (errno is set)
*/
int handle_signal(void)
{
	sig_t sigret;

	sigret = signal(SIGINT, handle_sigint);

	if (sigret == SIG_ERR)
		return (-1);
	return (0);
}
