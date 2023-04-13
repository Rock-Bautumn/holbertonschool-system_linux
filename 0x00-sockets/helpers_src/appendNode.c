#include "../server.h"

/**
 * appendNode - Adds a node to the end of the linked list that stores the
 * strings keys and values
 * @head: A pointer that holds the address of the pointer to the head node
 * @key: The key of the URL variable
 * @value: The value of the URL variable associated with the key
 * Return: void
*/
void appendNode(ll_node **head, char *key, char *value)
{
	ll_node *newNode = (ll_node *) malloc(sizeof(ll_node));
	ll_node *lastNode = *head;

	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		return;
	}

	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	lastNode->next = newNode;
}
