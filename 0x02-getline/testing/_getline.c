#include "_getline.h"

/**
 * _getline - returns a string delimited by the newline character from a file
 * @fd: the file descriptor of the file
 * Return: the string, now newline char at the end
*/

char *_getline(const int fd)
{
	char *buffer;
	char *output_string;
	int i;
	static int bytes_read;
	static char leftovers[READ_SIZE];
	
	buffer = read(fd, buffer, READ_SIZE);

	for (i = 0; i < READ_SIZE; i++)
	{
		if (buffer[i] == '\n')
			{
				return (i);
			}
		bytes_read += READ_SIZE;
		 
	}
	
	
	free(buffer);
	return (NULL);
}
