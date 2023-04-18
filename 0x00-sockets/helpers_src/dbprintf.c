#include "../server.h"

#ifndef DEBUG
#define DEBUG 0
#endif

int dbprintf(char const *format, ...)
{
	va_list va_items;
	size_t retval;

	if (!DEBUG)
		return (0);

	if (format)
	{
		va_start(va_items, format);
		retval = vprintf(format, va_items);
		va_end(va_items);
	}
	return (retval);
}
