#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "server.h"

int main(void)
{
	char buffer[4096];
	int testres;

	snprintf(buffer, 4096, "hello");
	snprintf(&buffer[strlen(buffer)], 1000, ", it's me again");


	testres = asnprintf(buffer, 4096, ". here's more%s", "... I hope that's okay!");
	printf("%s\n", buffer);

	printf("buff len is %ld, testres = %d\n", strlen(buffer), testres);

	if (asnprintf(NULL, 100, "Oopsies") == (ssize_t) -1)
	/* if ((ssize_t) -1 == -1) */
		printf("gotcha!\n");

	return 0;
}
