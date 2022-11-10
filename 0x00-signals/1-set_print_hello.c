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
	fflush(NULL);
}
/**
 * set_print_hello - Create a signal handler for SIGINT so that it uses
 *                  print_hello.
 * Return: void
*/
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
