#include "multithreading.h"

/**
 * thread_entry - entry point for the thread, prints the string passed to it
 * arg - The data string
 * Return - NULL
*/
void *thread_entry(void *arg)
{
	if (arg == NULL)
		pthread_exit(NULL);

	printf("%s\n", (char *) arg);

	pthread_exit(NULL);
	return (NULL);
}
