#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  "HOLBERTON SCHOOL"
#define S3  "Holberton SchooL"
#define S4  "holberton socool"
#define S5  "Holberton"

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    printf("|%d|\n", strncasecmp(S1, S2, 16));
    printf(">%d<\n", asm_strncasecmp(S1, S2, 16));
    fflush(NULL);
    if (strncasecmp(S1, S2, 16) == asm_strncasecmp(S1, S2, 16))
        printf("They matched!\n");
    assert(strncasecmp(S1, S3, 1) == asm_strncasecmp(S1, S3, 1));
    assert(strncasecmp(S1, S2, 11) == asm_strncasecmp(S1, S2, 11));
    assert(strncasecmp(S1, S3, 11) == asm_strncasecmp(S1, S3, 11));
    assert(strncasecmp(S1, S2, 16) == asm_strncasecmp(S1, S2, 16));
    assert(strncasecmp(S1, S3, 16) == asm_strncasecmp(S1, S3, 16));
    assert(strncasecmp(S1, S4, 11) == asm_strncasecmp(S1, S4, 11));
    assert(strncasecmp(S1, S4, 16) == asm_strncasecmp(S1, S4, 16));
    assert(strncasecmp(S1, S5, 16) == asm_strncasecmp(S1, S5, 9));
    assert(strncasecmp(S1, S4, 16) == asm_strncasecmp(S1, S4, 9));


    printf("All good!\n");
    return (EXIT_SUCCESS);
}
