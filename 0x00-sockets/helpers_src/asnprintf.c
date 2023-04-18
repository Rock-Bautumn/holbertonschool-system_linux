#include "../server.h"

ssize_t asnprintf(char *string, size_t size, char const *format, ...)
{
	va_list va_items;
	size_t used = 0, pls = 0;

	if (string != NULL)
		used = strlen(string);
	if (format)
	{
		va_start(va_items, format);
		if (string)
			pls = vsnprintf(&string[used], size - used, format, va_items);
		else
			pls = vsnprintf(NULL, 0, format, va_items);

		va_end(va_items);
	}
	dbprintf("asnprintf returned %lu\n", (used + pls));
	return (used + pls);
}
