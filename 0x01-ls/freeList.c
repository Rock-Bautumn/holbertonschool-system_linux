#include "main.h"

/**
 * freeList - Frees all of the items of a ** list and frees the list
 * @list: The list to free
 * Return: void
 */

void freeList(char **list, size_t size)
{
	int i = size;


	while (i > 0)
	{
		i--;
		if (&list[i] != NULL)
			free(list[i]);
	}

	free(list);
}
