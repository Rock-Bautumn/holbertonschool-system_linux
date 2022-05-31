#include "main.h"

int main(int argc, char *argv[]) {
	parsedCmdLine lsArgs;

	printf("Got %d arguments\n", argc);
	if (argc == 1)
		listFiles(".");
	else if (argc > 1)
	{
        initArgs(&lsArgs, argv[0]);
		parseArgs(&lsArgs, argv, argc);
		parseLocations(&lsArgs, argv, argc);
		outputResults(&lsArgs);
	}
	return 0;
}
