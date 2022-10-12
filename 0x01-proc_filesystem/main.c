#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/** main - This is the entry point to our program that will create a string
 *         in the heap, so that it can be modified by the read_write_heap.py
 *         file found in this directory.
 * Return: Success unless you are running this without any memory...
*/

int main(void)
{
	unsigned long int i = 0;
	char *string;

	string = strdup("Holberton School");
	printf("\n\n*           This will run indefinitely           *\n");
	printf("* A SIGINT signal is required to end the execution *\n\n\n");
	fflush(NULL);
	sleep(5);
	if (string == NULL)
		return (EXIT_FAILURE);
	for (; 1; i++)
	{
		printf("(%ld) String stored in heap is: %s ", i, string);
		printf("at address %p\n", (void *) string);
		sleep(1);
	}
	return (EXIT_SUCCESS);
}
