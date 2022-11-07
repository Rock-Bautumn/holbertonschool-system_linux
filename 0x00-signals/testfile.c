#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <limits.h>

/**
 * main - test stuff
 * @argc: number of arguments
 * @argv: argument list
 * Return: Success, hopefully
*/
int main(int argc, char **argv)
{
	int x;

	(void) argc;
	(void) argv;
	printf("%d\n", INT_MAX);
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (EXIT_SUCCESS);
}
