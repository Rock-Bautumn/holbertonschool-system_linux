#include "_getline.h"

void print_mem(char *first_byte, int length)
{
	int i;

	for (i = 0; i < length; i++)
	{
		printf("Address %p has value:", &first_byte[i]);
		putchar(*(first_byte + i));
		putchar('\n');
	}
	putchar('\n');
}


/**
 * _getline - returns a string delimited by the newline character from a file
 * @fd: the file descriptor of the file
 * Return: the string, now newline char at the end
*/

char *_getline(const int fd)
{
	char *buffer;
	char *last_buffer;
	char *searched_string = NULL;
	char *output_string;
	int i;
	int these_bytes_read;
	int bytes_read = 0;
	static char leftovers[DOUBLE_READ_SIZE];
	static int leftover_size;

	(void) searched_string;
	buffer = malloc(sizeof(char) * DOUBLE_READ_SIZE);
	do
	{
		if (leftover_size > 0) {
			these_bytes_read = leftover_size;
			
			printf("we found a leftover size of %d\n", these_bytes_read);
			memcpy(buffer, leftovers, leftover_size);
			printf("got leftovers:\n");
			print_mem(leftovers, leftover_size);
			
		}
		else
		{
			these_bytes_read = read(fd, buffer, READ_SIZE);
			printf("called read() to get %d bytes\n", these_bytes_read);
			printf("got buffer after read:\n");

			print_mem(buffer, these_bytes_read);
		}
		printf("now searching through bytes for newline\n");
		for (i = 0; i < (these_bytes_read - 1); i++)
		{
			if (buffer[i] == '\n')
			{
				memcpy(leftovers, &buffer[i+1], (READ_SIZE - i - 1));
				printf("entry leftovers:");
				print_mem(&buffer[i+1], (READ_SIZE - i - 1));
				leftover_size = READ_SIZE - i - 1;
				output_string = malloc(sizeof(char) * bytes_read + i + 1);
				buffer[i] = '\0';
				if (output_string == NULL)
					return (NULL);
				if (searched_string)
				{
					printf("inside confirmed search_string\n");
					memcpy(output_string, searched_string, bytes_read);
					memcpy(output_string + bytes_read + 1, buffer, i);
					free(buffer);
					free(searched_string);
					printf("we search_string output_string is |%s|\n", output_string);

					return (output_string);
				}
				else
				{
					memcpy(output_string, buffer, i);
					printf("output_string sizeof is %lu\n", sizeof(output_string));
					output_string[i] = '\0';
					printf("we output_string is |%s|\n", output_string);
					free(buffer);
					return (output_string);
				}
			}
		}
		
		if (these_bytes_read == READ_SIZE)
		{
			bytes_read += READ_SIZE;
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
				searched_string = realloc(searched_string, sizeof(char) * bytes_read);
				memcpy(searched_string + bytes_read + 1, buffer, these_bytes_read);
			}
		}

		printf("thsereadbytes = %d\n", these_bytes_read);
	
	printf("sleeping...\n");
	sleep(2);
	
		last_buffer = malloc(sizeof(char) * READ_SIZE);
		these_bytes_read = read(fd, last_buffer, READ_SIZE);
		
			printf("last_buffer contains:\n");
			/* print_mem(last_buffer, READ_SIZE); */
			printf("last these bytes is %d\n", these_bytes_read);
			memcpy(&leftovers[leftover_size], last_buffer, these_bytes_read);
			leftover_size = leftover_size + these_bytes_read;
		
		free(last_buffer);
		printf("last last these bytes is %d\n", these_bytes_read);
	} while (these_bytes_read > 0);
	/*
	if (i > 0)
		return buffer;
	*/
	free(buffer);
	free(searched_string);
	return (NULL);
}
