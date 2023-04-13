#include "server.h"

void removeSpaces(char *string)
{
	size_t length, pos = 0, swap = 0;

	if (string == NULL)
		return;

	length = strlen(string);

	for (; string[pos] == ' '; pos++);

	for (; pos < length; string[swap++] = string[pos++]);

	string[swap] = '\0';

	length = strlen(string);

	pos = length - 1;

	for (; string[pos] == ' '; pos--);

	string[pos + 1] = '\0';
}


int main()
{
	char str[] = "  Hello, World!    ";

	printf("Before: [%s]\n", str);
	removeSpaces(str);
	printf("After: [%s]\n", str);

	return (0);
}
