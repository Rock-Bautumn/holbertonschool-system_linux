#include "../server.h"

void generateAndSendResponse(int sock_fd, int http_code, size_t jsonLen, char *json)
{
	size_t respSize = jsonLen + 1;
	char *res = NULL, http_str[50] = {0};

	if (http_code == 200)
		strcpy(http_str, HTTP_OK_H);
	else
		strcpy(http_str, HTTP_201_H);

	respSize += strlen(http_str);
	respSize += strlen("Content-Length: \r\n");
	respSize += strlen("Content-Type: application/json\r\n");
	respSize += strlen("\r\n\r\n");
	dbprintf("json in gen is: %s\n", json);
	res = malloc(respSize + 1);
	asnprintf(res, respSize, "%s%s %lu\r\n%s\r\n%s\r\n\r\n",
		http_str, "Content-Length:", jsonLen,
		"Content-Type: application/json\r\n", json);
	dbprintf("\nSENDING THIS TO CLIENT:\n%s", res);
	replyToClient(sock_fd, res);
	free(res);
}
