#include "multithreading.h"

/**
 * tprintf - prints the id of the thread id and the string passed to it
 * @format: the format specifier string
 * Return - Always 0
*/

int tprintf(char const *format, ...)
{
	if (format)
	{
		printf("[%lu] %s", pthread_self(), format);
		return (0);
	}
	
	pthread_exit(NULL);
}
