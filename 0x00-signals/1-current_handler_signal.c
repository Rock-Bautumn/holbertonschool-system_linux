#include "signals.h"

/**
 * current_handler_signal - return the handler for the interrupt signal
 * Return: The address of the sigint handler function
*/
void (*current_handler_signal(void))(int)
{
	__sighandler_t handle_func;

	handle_func = signal(SIGINT, NULL);
	if (handle_func == SIG_ERR)
		return (NULL);
	signal(SIGINT, handle_func);
	return (handle_func);
}
