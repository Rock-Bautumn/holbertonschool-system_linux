#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char *key;
	char *value;
	struct Node *next;
} ll_node;

void appendNode(struct Node **head, char *key, char *value)
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

size_t char_occurrences(char *string, char chr)
{
	size_t count = 0, check_pos = 0;

	for (; string[check_pos]; check_pos++)
		if (string[check_pos] == chr)
			count++;

	return (count);
}
/*
int main(void)
{
	char queryString[] = "key1=value1&key2=value2&key3=value3";
	char *pair, *key, *value;
	ll_node *head = NULL, *current = NULL;

	pair = strtok(queryString, "&");
	printf("pair is %s\n", pair);
	while (pair != NULL)
	{
		key = strtok(pair, "=");
		value = strtok(NULL, "=");
		appendNode(&head, key, value);

		pair = strtok(NULL, "&");
		printf("next pair is %s\n", pair);
	}

	current = head;

	while (current != NULL)
	{
		printf("Key: %s, Value: %s\n", current->key, current->value);
		current = current->next;
	}

	return (0);
}
*/


int parseQueryString(ll_node *head, char *qs)
{
	size_t param_index = 0, occs;
	char *token, *next_token, *key, *value;
	ll_node *current;

	occs = char_occurrences(qs, '&');
	token = strtok(qs, "&");
	for (; param_index <= occs; token = strtok(token,"&"))
	{
		param_index++;
		next_token = token + strlen(token) + 1;
		key = strtok(token, "=");
		value = strtok(NULL, "=");
		appendNode(&head, key, value);
		token = next_token;
	}

	for (current = head; current != NULL; current = current->next)
		printf("Key: %s, Value: %s\n", current->key, current->value);

	return 0;
}

int main ()
{
	char querystring[]="a=1&b&c=3&d=&meh=5";
	ll_node *head = NULL;

	parseQueryString(head, querystring);

	return 0;

}



/*
int main()
{

    char querystring[]="a=1&b&c=3&d=&meh=5";
    int pc=0;
    char *tok;
    char *otok;
    
    for(tok=strtok(querystring,"&");tok!=NULL;tok=strtok(tok,"&")) {
        pc++;
        otok=tok+strlen(tok)+1;
        tok=strtok(tok,"=");
	printf("key strlen is %ld\n", strlen(tok));
        fprintf(stderr,"param%d: %s ",pc,tok);
        tok=strtok(NULL,"=");
        fprintf(stderr,"value%d: %s\n",pc,tok);
        tok=otok;
    };
    return 0;
}
*/
