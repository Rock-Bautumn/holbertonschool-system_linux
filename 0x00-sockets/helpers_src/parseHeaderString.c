#include "../server.h"

/**
 * parseHeaderstring - Store the keys and values of the query string into
 * a singly linked list
 * @head: Pointer to the address (pointer again) of the head node
 * @hs: The query string to parse
 * Return: The new head node's address
*/

ll_node *parseHeaderString(ll_node **head, char *hs)
{
	char *str1, *str2, *token, *subtoken, *saveptr1, *saveptr2, *key;
	char sub_char;
	int j, step;

	if (hs == NULL)
		return (NULL);

	for (j = 1, str1 = hs; ; j++, str1 = NULL)
	{
		token = strtok_r(str1, "\r\n", &saveptr1);
		if (token == NULL)
			break;
		if (char_occurrences(token, ':') > 1)
			sub_char = sub_after_one(token, ':');
		for (str2 = token, step = 0; ; str2 = NULL, step++)
		{
			subtoken = strtok_r(str2, ":", &saveptr2);
			if (subtoken == NULL)
				break;
			if (strchr(subtoken, sub_char))
				replace_chars(subtoken, sub_char, ':');
			if (step == 0)
				key = subtoken;
			else
				appendNode(head, key, trimSpaces(subtoken));
		}
	}

	return (*head);
}
