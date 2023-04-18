#ifndef _SERVER_H_
#define _SERVER_H_

#define DEBUG 1

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>

#include <netinet/tcp.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <arpa/inet.h>

#define HTTP_OK "200 OK"
#define HTTP_201 "201 Created"
#define HTTP_404 "404 Not Found"
#define HTTP_411 "411 Length Required"
#define HTTP_422 "422 Unprocessable Entity"

#define HTTP_OK_H "HTTP/1.1 200 OK\r\n"
#define HTTP_201_H "HTTP/1.1 201 Created\r\n"

#define HTTP_OK_R "HTTP/1.1 200 OK\r\n\r\n"
#define HTTP_404_R "HTTP/1.1 404 Not Found\r\n\r\n"
#define HTTP_411_R "HTTP/1.1 411 Length Required\r\n\r\n"
#define HTTP_422_R "HTTP/1.1 422 Unprocessable Entity\r\n\r\n"


typedef struct Node
{
	size_t id;
	char *key;
	char *value;
	struct Node *next;
} ll_node;

typedef struct TDNode
{
	size_t id;
	char *key;
	char *value;
	char *key2;
	char *value2;
	struct TDNode *next;
} ll_tdnode;

void appendNode(ll_node **head, char *key, char *value);
void appendTDNode(ll_tdnode **head, char *key, char *value, char *key2, char *value2);
ssize_t asnprintf(char *string, size_t size, char const *format, ...);
size_t char_occurrences(char *string, char chr);
int dbprintf(char const *format, ...);
void ErrorAndDie(char *string);
char *extractPathAsCopy(char *http_info);
char *extractQueryAsCopy(char *http_info);
void generateAndSendResponse(int sock_fd, int http_code, size_t jsonLen, char *json);
void httpToClient(int sock_fd, int http_code);
size_t jsonLength(ll_tdnode *head);
size_t jsonifyList(char *json, size_t jsonLen, ll_tdnode *tdhead);
ll_tdnode *lastTDNode(ll_tdnode **start_point);
bool listHasKey(ll_node *head, char *key);
char **ndsplitter(char *fun, char *delimiter);
ll_node *parseHeaderString(ll_node **head, char *hs);
ll_node *parseQueryString(ll_node **head, char *qs);
int parseTDQueryString(ll_tdnode **head, char *qs);
void replyToClient(int sock_fd, char *msg);
void replace_chars(char *string, char old, char new);
int space_count(char *str, char *delimiter);
char sub_after_one(char *string, char chr);
bool validTDitem(char *key, char *value, char *key2, char *value2);

/**
 * trimSpaces - Remove the leading and trailing spaces from a string.
 * This function keeps the address of the string the same, so IT IS SAFE to
 * free() this string if it was allocated using malloc()!
 * @string: The string to trim the leading and trailing spaces from
 * Return: void
*/
char *trimSpaces(char *string);


#endif /* _SERVER_H_ */
