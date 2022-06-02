#include "main.h"

int main(int argc, char *argv[]) {
	parsedCmdLine lsArgs;

	printf("Got %d arguments\n", argc);
	initArgs(&lsArgs, argv[0]);
	if (argc == 1)
		listFiles(&lsArgs, ".");
	else if (argc > 1)
	{
		parseArgs(&lsArgs, argv, argc);
		parseLocations(&lsArgs, argv, argc);
		outputResults(&lsArgs);
	}
	return 0;
}
