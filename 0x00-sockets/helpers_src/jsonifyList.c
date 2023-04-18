#include "../server.h"

size_t jsonifyList(char *json, size_t jsonLen, ll_tdnode *tdhead)
{
	size_t len = 0;
	char *titleVal = NULL, *descVal = NULL;
	ll_tdnode *t_n = tdhead;
	int node_iterations = 1;

	
	if (tdhead == NULL)
		strncpy(json, "", 1);
	
	for (; t_n; t_n = t_n->next, node_iterations++)
	{
		if (t_n->next && node_iterations == 1)
			asnprintf(json, jsonLen, "[");

		if (strcmp(t_n->key, "title") == 0)
		{
			titleVal = t_n->value;
			descVal = t_n->value2;
		}
		else
		{
			titleVal = t_n->value2;
			descVal = t_n->value;
		}

len += asnprintf(json, jsonLen,
"{\"id\":%ld,\"title\":\"%s\",\"description\":\"%s\"}%s",
t_n->id, titleVal, descVal, (t_n->next != NULL ? "," : ""));

		if (node_iterations == 2)
			len += 2;
	}
	if (node_iterations > 1)
		asnprintf(json, jsonLen, "]");
	dbprintf("\n\njsonify made: %s\n", json);
	return (len);
}
