#include "../server.h"

/**
 * appendTDNode - Adds a node to the end of the linked list that stores the
 * string keys and values of a todo list item
 * @head: A pointer that holds the address of the pointer to the head node
 * @key: The key of the first URL variable
 * @value: The value of the URL variable associated with the first key
 * @key2: The key of the second URL variable
 * @value2: The value of the URL variable associated with the second key
 * Return: void
*/
void appendTDNode(
ll_tdnode **head, char *key, char *value, char *key2, char *value2)
{
	ll_tdnode *newNode = (ll_tdnode *) malloc(sizeof(ll_tdnode));
	ll_tdnode *lastNode = *head;

	newNode->key = key;
	newNode->value = value;
	newNode->key2 = key2;
	newNode->value2 = value2;
	newNode->next = NULL;

	dbprintf("in appendTDNode, this node print-out:\n");
	dbprintf("key = %s\n", newNode->key);
	dbprintf("value = %s\n", newNode->value);
	dbprintf("key2 = %s\n", newNode->key2);
	dbprintf("value2 = %s\n", newNode->value2);
	dbprintf("those are the values we found in this node in appendTDnode\n\n");

	if (*head == NULL)
	{
		newNode->id = 0;
		*head = newNode;
		return;
	}

	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	newNode->id = lastNode->id + 1;
	lastNode->next = newNode;
}
