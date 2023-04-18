#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"


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

void replace_chars(char *string, char old, char new)
{
	size_t search_pos = 0;

	if (string == NULL || old == new)
		return;

	for (; string[search_pos]; search_pos++)
		if (string[search_pos] == old)
			string[search_pos] = new;
}

int main(int argc, char *argv[])
{
	char *str1, *str2, *token, *subtoken, *saveptr1, *saveptr2, *key;
	char sub_char;
	int j, step;
	ll_node *head = NULL, *current;

	if (argc != 4) {
		fprintf(stderr, "Usage: %s string delim subdelim\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}

	for (j = 1, str1 = argv[1]; ; j++, str1 = NULL) {
		token = strtok_r(str1, "\n", &saveptr1);
		if (token == NULL)
			break;
		if (char_occurrences(token, ':') > 1)
			sub_char = sub_after_one(token, '=');
		for (str2 = token, step = 0; ; str2 = NULL, step++) {
			subtoken = strtok_r(str2, "=", &saveptr2);
			if (subtoken == NULL)
				break;
			if (strchr(subtoken, sub_char))
				replace_chars(subtoken, sub_char, '=');
			if (step == 0)
				key = subtoken;
			else
				appendNode(&head, key, trimSpaces(subtoken));
		}
	}

	current = head;

	while (current != NULL)
	{
		printf("Header: \"%s\" -> \"%s\"\n",
			current->key, current->value);
		current = current->next;
	}

	exit(EXIT_SUCCESS);
}
