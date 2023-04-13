#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>

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
size_t char_occurrences(char *string, char chr);
void ErrorAndDie(char *string);
char *extractPathAsCopy(char *http_info);
char *extractQueryAsCopy(char *http_info);
char **ndsplitter(char *fun, char *delimiter);
ll_node *parseHeaderString(ll_node **head, char *hs);
ll_node *parseQueryString(ll_node **head, char *qs);
void replace_chars(char *string, char old, char new);
int space_count(char *str, char *delimiter);
char sub_after_one(char *string, char chr);

/**
 * trimSpaces - Remove the leading and trailing spaces from a string.
 * This function keeps the address of the string the same, so IT IS SAFE to
 * free() this string if it was allocated using malloc()!
 * @string: The string to trim the leading and trailing spaces from
 * Return: void
*/
char *trimSpaces(char *string);


#endif /* _SERVER_H_ */
