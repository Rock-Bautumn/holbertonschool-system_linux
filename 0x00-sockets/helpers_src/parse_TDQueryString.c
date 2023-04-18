#include "../server.h"

/**
 * parseTDQueryString - Store the keys and values of the query string into
 * a todo singly linked list
 * @head: Pointer to the address (pointer again) of the head node
 * @qs: The query string to parse
 * Return: The new head node's address
*/

int parseTDQueryString(ll_tdnode **head, char *qs)
{
	char *str1, *str2, *token, *subtoken;
	char *saveptr1, *saveptr2, *key = NULL, *value = NULL, *key2, *value2;
	int j, k;

	for (j = 1, str1 = qs; ; j++, str1 = NULL)
	{
		token = strtok_r(str1, "&", &saveptr1);
		if (token == NULL)
			break;

		for (k = 1, str2 = token; ; k++, str2 = NULL)
		{
			subtoken = strtok_r(str2, "=", &saveptr2);
			if (subtoken == NULL)
				break;
			if (j == 1)
			{
				if (k == 1)
					key = subtoken;
				else if (k == 2)
					value = subtoken;
			}
			else if (j == 2)
			{
				if (k == 1)
					key2 = subtoken;
				else if (k == 2)
					value2 = subtoken;
			}
		}
	}
	if (!validTDitem(key, value, key2, value2))
		return (-1);

	appendTDNode(head, key, value, key2, value2);
	return (0);
}
