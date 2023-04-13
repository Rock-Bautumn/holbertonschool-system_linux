#include "../server.h"

char sub_after_one(char *string, char chr)
{
	size_t search_pos = 0;
	bool found_the_first = false;
	char sub_char = 1;

	for (; strchr(string, sub_char); sub_char++)
		if (sub_char == 127)
		{
			errno = EIO;
			ErrorAndDie("Char sub failed, all chars in use");
		}
	for (; string[search_pos]; search_pos++)
		if (string[search_pos] == chr)
		{
			if (found_the_first == false)
				found_the_first = true;
			else
				string[search_pos] = sub_char;
		}

	return (sub_char);
}
