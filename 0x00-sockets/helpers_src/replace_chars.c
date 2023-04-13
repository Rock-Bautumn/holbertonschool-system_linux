#include "../server.h"

void replace_chars(char *string, char old, char new)
{
	size_t search_pos = 0;

	if (string == NULL || old == new)
		return;

	for (; string[search_pos]; search_pos++)
		if (string[search_pos] == old)
			string[search_pos] = new;
}
