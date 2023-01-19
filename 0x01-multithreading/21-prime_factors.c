#include "multithreading.h"
#include "list.h"

/**
 * prime_factors - find the prime factors of a string number and
 * save it into an unnecessarily complicated linked list because
 * somehow fighting the data structures is teaching us multithreading
 * @s: a string of numbers to be converted into a number
 * Return: The head of the needlessly complicated linked list
*/

list_t *prime_factors(char const *s)
{
	size_t i, num;
	list_t *head;
	size_t *factor;

	if (!s)
		return (NULL);
	num = strtoul(s, NULL, 10);

	head = malloc(sizeof(list_t));
	if (!head)
		return (NULL);

	head = list_init(head);

	for (i = 2; i <= num; i += (i == 2) ? 1 : 2)
	{
		while (num % i == 0)
		{
			factor = malloc(sizeof(size_t));
			*factor = i;
			list_add(head, factor);
			num /= i;
		}
	}
	return (head);
}
