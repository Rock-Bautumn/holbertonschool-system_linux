#include "../server.h"

/**
 * listHasKey - Checks if a linked list contains a node with a key
 * @head: The head node of the linked list
 * @key: The key to search for in the linked list
 * Return: true if the key is found in the linked list, false if it is not
*/

bool listHasKey(ll_node *head, char *key)
{
	ll_node *t_n = head;

	for (; t_n != NULL; t_n = t_n->next)
		if (strcmp(t_n->key, key) == 0)
			return (true);

	return (false);
}
