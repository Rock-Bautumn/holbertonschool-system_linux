#include "../server.h"

size_t jsonLength(ll_tdnode *head)
{
	size_t len = 0;
	ll_tdnode *t_n = head;
	/* char buff[5000]; */
	int node_iterations = 1;

	while (t_n != NULL)
	{
		if (t_n->next && node_iterations == 1)
			asnprintf(NULL, 5000, "[");
len += asnprintf(NULL, 0,
"{\"id\":%ld,\"title\":\"%s\",\"description\":\"%s\"}%s",
t_n->id, t_n->value, t_n->value2, (t_n->next != NULL ? "," : ""));

		t_n = t_n->next;
		if (node_iterations == 2)
			len += 2;
		node_iterations++;
	}
	if (node_iterations > 1)
		asnprintf(NULL, 5000, "]");
	/* printf("\n\nmade: %s\n", buff); */
	return (len);
}
