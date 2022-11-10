#include <unistd.h>
#include <signal.h>
#include <stdio.h>

/**
 * catch_and_quit - print a message that a signal was received
 * @sig: the signal
 * Return: void
*/
void catch_and_quit(int sig)
{
	printf("Caught %d\nSignal received\n", sig);
}
/**
 * handle_sigaction - register a signal using sigaction
 * Return: the result of sigaction()
*/
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = &catch_and_quit;
	sa.sa_flags = SA_RESTART;

	return (sigaction(SIGINT, &sa, NULL));
}

/**
 * main - entry point, waits until it receives interrupt signal then quits
 * Return: zero
*/

int main(void)
{
	handle_sigaction();
	pause();
	return (0);
}
