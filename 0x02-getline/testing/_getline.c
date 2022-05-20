#include "_getline.h"

/**
 * _getline - returns a string delimited by the newline character from a file
 * @fd: the file descriptor of the file
 * Return: the string, now newline char at the end
*/

char *_getline(const int fd)
{
	char *buffer;
	char *searched_string;
	char *output_string;
	int i;
	int these_bytes_read;
	int bytes_read = 0;
	static char leftovers[READ_SIZE];

	(void) searched_string;
	buffer = malloc(sizeof(char) * READ_SIZE);
	do
	{
		if (sizeof(leftovers) > 0) {
			these_bytes_read = sizeof(leftovers);
			memcpy(buffer, leftovers, READ_SIZE);
		}
		else
			these_bytes_read = read(fd, buffer, READ_SIZE);

		for (i = 0; i < these_bytes_read; i++)
		{
			if (buffer[i] == '\n')
			{
				memcpy(leftovers, &buffer[i+1], (READ_SIZE - i));
				output_string = malloc(sizeof(char) * bytes_read + i + 1);
				if (output_string == NULL)
					return (NULL);
				if (searched_string != NULL)
				{
					memcpy(output_string, searched_string, bytes_read);
					memcpy(output_string + bytes_read + 1, buffer, i + 1);
					output_string[(sizeof(output_string) - 1)] = '\n';
					free(buffer);
					return (output_string);
				}
				else
				{
					memcpy(output_string, buffer, i + 1);
					output_string[(sizeof(output_string) - 1)] = '\n';
					free(buffer);
					return (output_string);
				}
			}
		}
		bytes_read += READ_SIZE;
		if (these_bytes_read == READ_SIZE)
		{
			if (bytes_read == READ_SIZE)
			{
				searched_string = malloc(sizeof(char) * READ_SIZE);
				memcpy(searched_string, buffer, READ_SIZE);
			}
			else
			{
				printf("going to realloc with current %s\n", searched_string);
				printf("size of searched_string is %lu\n", sizeof(searched_string));
				printf("new realloc size = %ld\n", (sizeof(char) * bytes_read + 1));
				searched_string = realloc(searched_string, sizeof(char) * bytes_read + 1);
				memcpy(searched_string + bytes_read + 1, buffer, these_bytes_read);
			}
		}
	} while (these_bytes_read > 0);
	if (i > 0)
		return buffer;
	free(buffer);
	return (NULL);
}
