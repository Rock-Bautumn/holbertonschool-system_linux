#include "multithreading.h"

int tprintf(char const *format, ...)
{

	printf("[%lu] %s", pthread_self(), format);
	pthread_exit(NULL);
	return (0);
}
