#include "../server.h"

void httpToClient(int sock_fd, int http_code)
{
	switch (http_code)
	{
	case 201:
		printf("%s\n", HTTP_201);
		replyToClient(sock_fd, HTTP_201_H "\r\n");
		break;
	case 404:
		printf("%s\n", HTTP_404);
		replyToClient(sock_fd, HTTP_404_R);
		break;
	case 411:
		printf("%s\n", HTTP_411);
		replyToClient(sock_fd, HTTP_411_R);
		break;
	case 422:
		printf("%s\n", HTTP_422);
		replyToClient(sock_fd, HTTP_422_R);
		break;
	default:
		printf("%s\n", HTTP_OK);
		replyToClient(sock_fd, HTTP_OK_R);
		break;
	}
}
