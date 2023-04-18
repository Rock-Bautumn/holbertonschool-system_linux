#include "../server.h"

ll_tdnode *lastTDNode(ll_tdnode **start_point)
{
	ll_tdnode *this_node = *start_point;

	while (this_node->next != NULL)
		this_node = this_node->next;

	dbprintf("return this node data as last TD node:\n");
	dbprintf("%s - %s\n", this_node->value, this_node->value2);
	dbprintf("end lasttdnode\n");
	return (this_node);
}
