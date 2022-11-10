#include "signals.h"

/**
 * print_hello - print a message that a signal was received
 * @signo: the signal
 * Return: void
*/
void print_hello(int signo)
{
	(void) signo;
	puts("Hello :)");
}

/**
 * set_print_hello - register a signal handler for print_hello()
 * Return: void
*/
void set_print_hello(void)
{
	struct sigaction sa;

	sa.sa_handler = &print_hello;
	sigaction(SIGINT, &sa, NULL);
}
