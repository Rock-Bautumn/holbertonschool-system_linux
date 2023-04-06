#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#ifndef __USE_XOPEN2K
#define __USE_XOPEN2K
#endif
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(void)
{
	struct addrinfo hints, *res = NULL;
	struct sockaddr_in *server_addr = NULL;
	char ip_addr_buf[INET_ADDRSTRLEN];

	memset(&hints, 0x00, sizeof(struct addrinfo));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;


	if (getaddrinfo("localhost", NULL, &hints, &res))
	{
	/* handle error */
	}

	server_addr = (struct sockaddr_in *)res->ai_addr;
	inet_ntop(AF_INET, &(server_addr->sin_addr), ip_addr_buf, INET_ADDRSTRLEN);
	printf("'localhost' IP address: %s\n", ip_addr_buf);

	freeaddrinfo(res);

	return 0;
}
