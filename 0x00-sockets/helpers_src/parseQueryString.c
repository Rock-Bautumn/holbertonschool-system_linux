#include "../server.h"

/**
 * parseQueryString - Store the keys and values of the query string into
 * a singly linked list
 * @head: Pointer to the address (pointer again) of the head node
 * @qs: The query string to parse
 * Return: The new head node's address
*/

ll_node *parseQueryString(ll_node **head, char *qs)
{
	size_t param_index = 0, occs;
	char *token, *next_token, *key, *value;

	occs = char_occurrences(qs, '&');
	token = strtok(qs, "&");
	for (; param_index <= occs; token = strtok(token, "&"))
	{
		param_index++;
		next_token = token + strlen(token) + 1;
		key = strtok(token, "=");
		value = strtok(NULL, "=");
		appendNode(head, key, value);
		token = next_token;
	}

	return (*head);
}
