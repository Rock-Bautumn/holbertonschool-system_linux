#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"

#define S1  "Holberton School"
#define S2  "HOLBERTON SCHOOL"
#define S3  "Holberton SchooL"
#define S4  "HoLberton socool"
#define S5  "hello"
#define S6  "Holberton"
#define S7  "HOLBERTON School"
#define S8  ""

/**
 * main - Program entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    printf("|%d|\n", strcasecmp(S1, S6));
    printf(">%d<\n", asm_strcasecmp(S1, S6));
    fflush(NULL);
    if (strcasecmp(S1, S6) == asm_strcasecmp(S1, S6))
        printf("They matched!\n");
    assert(strcasecmp(S1, S1) == asm_strcasecmp(S1, S1));
    assert(strcasecmp(S1, S2) == asm_strcasecmp(S1, S2));
    assert(strcasecmp(S1, S3) == asm_strcasecmp(S1, S3));
    assert(strcasecmp(S1, S4) == asm_strcasecmp(S1, S4));
    assert(strcasecmp(S1, S6) == asm_strcasecmp(S1, S6));
    assert(strcasecmp(S7, S6) == asm_strcasecmp(S7, S6));
    assert(strcasecmp(S6, S1) == asm_strcasecmp(S6, S1));
    assert(strcasecmp(S6, S8) == asm_strcasecmp(S6, S8));
    assert(strcasecmp(S8, S6) == asm_strcasecmp(S8, S6));
    
    



    printf("All good!\n");
    return (EXIT_SUCCESS);
}
