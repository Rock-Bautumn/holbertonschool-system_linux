#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  ""
#define S3  "Holberton Socool"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{

	printf("1 is %d\n", strcmp(S1, S1));
	printf("2 is %d\n", strcmp(S1, S2));
	printf("3 is %d\n", strcmp(S1, S3));
    assert(strcmp(S1, S1) == asm_strcmp(S1, S1));
    assert(strcmp(S1, S2) == asm_strcmp(S1, S2));
    assert(strcmp(S1, S3) == asm_strcmp(S1, S3));
    printf("All good!\n");
    return (EXIT_SUCCESS);
}
