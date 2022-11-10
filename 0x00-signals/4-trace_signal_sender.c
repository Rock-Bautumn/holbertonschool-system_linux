#include "signals.h"

/**
 * handler - print a message that a signal was received
 * @sig: the signal
 * @info: the information struct about the signal
 * @vp: unused
 * Return: void
*/
void handler(int sig, siginfo_t *info, void *vp)
{
	(void) sig;
	(void) vp;
	printf("SIGQUIT sent by %d\n", info->si_pid);
}

/**
 * trace_signal_sender - create the handler to report which pid sent the signal
 * Return: 0 if success, -1 if fail.
*/
int trace_signal_sender(void)
{
	struct sigaction action, old_action;

	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART | SA_SIGINFO;

	if (sigaction(SIGQUIT, &action, &old_action) < 0)
		return (-1);
	return (0);
}


