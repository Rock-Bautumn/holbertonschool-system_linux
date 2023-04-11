#include "../server.h"

/**
 * extractQueryAsCopy - Return a copied (strdup) string of the query in the URL
 * @http_info: The first line of the HTTP request, for example:
 * (GET /example?key=value HTTP/1.1)
 * Return: The query string part of the URL (key=value from above example)
*/

char *extractQueryAsCopy(char *http_info)
{
	size_t char_pos, start = 0, end;

	for (char_pos = 0; http_info[char_pos]; char_pos++)
	{
		if (http_info[char_pos] == '?')
		{
			if (start == 0)
				start = char_pos + 1;
		}
		if (http_info[char_pos] == ' ')
			end = char_pos;
	}

	return (strndup(&http_info[start], end - start));
}
