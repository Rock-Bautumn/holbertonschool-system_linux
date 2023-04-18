#include "../server.h"

void generateAndSendResponse(int sock_fd, int http_code, size_t jsonLen, char *json)
{
	size_t respSize = jsonLen + 1;
	char *res = NULL, http_str[50] = {0};

	if (http_code == 200)
	{
		strcpy(http_str, HTTP_OK_H);
		if (json[0] != '[' && strlen(json) != 0)
			jsonLen += 2;
	}
	else
		strcpy(http_str, HTTP_201_H);

	respSize += strlen(http_str);
	respSize += strlen("Content-Length: \r\n");
	respSize += strlen("Content-Type: application/json\r\n");
	respSize += strlen("\r\n\r\n");
	dbprintf("GEN json in is: %s\n", json);
	res = malloc(respSize + 1);
	asnprintf(res, respSize, "%s%s %lu\r\n%s\r\n",
		http_str, "Content-Length:", jsonLen,
		"Content-Type: application/json\r\n");
	if (http_code == 200 && json[0] != '[')
		strcat(res, "[");
	strcat(res, json);
	if (http_code == 200 && json[0] != '[')
		strcat(res, "]");
	strcat(res, "\r\n\r\n");
	dbprintf("\nSENDING THIS TO CLIENT:\n%s", res);
	replyToClient(sock_fd, res);
	free(res);
}
