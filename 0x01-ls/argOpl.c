#include "main.h"

void argOpl(parsedCmdLine *theseLSargs, char thisArg)
{
	(void) thisArg;
	printf("ArgOpl triggered!\n");
	theseLSargs->option_l = 1;
}