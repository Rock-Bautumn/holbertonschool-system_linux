#include "main.h"

void printList(char **theList, size_t size)
{
	size_t i;

	printf("printing list:\n");
	for (i = 0; i < size; i++)
	{
		printf("%s ", theList[i]);
	}
	printf("\n");
}
