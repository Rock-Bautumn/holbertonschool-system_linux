#include "multithreading.h"

/**
 * beginMutex - Initializes the global mutex item
*/

void beginMutex (void)
{
	pthread_mutex_init(&the_mutex, NULL);
}

/**
 * endMutex - Destroys the global mutex item
*/

void endMutex (void)
{
	pthread_mutex_destroy(&the_mutex);
}

/**
 * tprintf - Print the thread id and accompanying text
 * @format: The format string
 * Return: EXIT_SUCCESS
*/

int tprintf(char const *format, ...)
{
	va_list va_items;

	pthread_mutex_lock(&the_mutex);
	if (format)
	{
		va_start(va_items, format);
		printf("[%lu] ", pthread_self());
		vprintf(format, va_items);
		va_end(va_items);
	}
	pthread_mutex_unlock(&the_mutex);
	return (EXIT_SUCCESS);
}
