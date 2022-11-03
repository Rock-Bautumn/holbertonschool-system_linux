/* Description: `asm_strcasecmp("Holberton School", "Holberton")` */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1	"Holberton School"
#define S2	"Holberton"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	printf("|%d|\n", strcasecmp(S1, S2));
    	printf(">%d<\n", asm_strcasecmp(S1, S2));
    	fflush(NULL);

	assert(strcasecmp(S1, S2) == asm_strcasecmp(S1, S2));


	printf("All good!\n");
	return (EXIT_SUCCESS);
}
