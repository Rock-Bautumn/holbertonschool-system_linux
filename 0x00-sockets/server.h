#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <arpa/inet.h>


typedef struct Node
{
	char *key;
	char *value;
	struct Node *next;
} ll_node;

void appendNode(ll_node **head, char *key, char *value);
void ErrorAndDie(char *string);
char *extractPathAsCopy(char *http_info);
char *extractQueryAsCopy(char *http_info);

size_t char_occurrences(char *string, char chr);
char **ndsplitter(char *fun, char *delimiter);
ll_node *parseQueryString(ll_node **head, char *qs);
int space_count(char *str, char *delimiter);


#endif /* _SERVER_H_ */
