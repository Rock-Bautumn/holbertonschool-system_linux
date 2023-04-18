#include "../server.h"

bool validTDitem(char *key, char *value, char *key2, char *value2)
{
	if (strcmp(key, "title") != 0 && strcmp(key2, "title") != 0)
		return (false);
	if (strcmp(key, "description") != 0 && strcmp(key2, "description") != 0)
		return (false);
	if (value == NULL || value2 == NULL)
		return (false);

	printf("it was a valid list\n");
	return (true);
}
