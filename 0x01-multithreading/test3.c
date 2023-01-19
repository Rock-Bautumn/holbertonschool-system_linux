#include <stdlib.h>
#include <stdio.h>

size_t prime_factors(char const *s)
{
	size_t num = strtoul(s, NULL, 10);

	return num;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (EXIT_FAILURE);

	printf("%lu\n", prime_factors(av[1]));
	return 0;
}
