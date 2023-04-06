
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#ifndef __USE_XOPEN2K
#define __USE_XOPEN2K
#endif
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

/**
 * ErrorAndDie - Print an error message with perror and exit with failure
 * @string: The error message to print with perror
 * Return: void
*/
void ErrorAndDie(char *string)
{
	perror(string);
	exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[])
{
	int sock_fd = 0, port = atoi(argv[2]), error;
	struct sockaddr_in sock_addr;
	struct addrinfo *host_addr_info;

	if (argc < 2)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd < 0)
		ErrorAndDie("Unable to create socket");

	memset(&sock_addr, '0', sizeof(sock_addr));

	error = getaddrinfo(argv[1], NULL, NULL, &host_addr_info);
	if (error != 0)
		ErrorAndDie("getaddrinfo failed");

	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(port);


	error = inet_pton(AF_INET, (char *) &host_addr_info->ai_addr, &sock_addr.sin_addr);
	if (error != 0)
		ErrorAndDie("getaddrinfo failed");

	printf("resolved address of %s to %s\n", argv[1], inet_ntoa(ntohl(sock_addr.sin_addr.s_addr
	)));


	if (connect(sock_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
		ErrorAndDie("Connection Failed");

	printf("Connected to server!");
	return (EXIT_SUCCESS);
}
