#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av)
{
	size_t i;

	(void) ac;
    (void) av;

	printf("%lu\n", ULONG_MAX);

    for (i = 0; i < ULONG_MAX; i++)
    {
        if (i % 1000000000 == 0)
            printf("%ld\n", i);
    }
    return 0;
}
