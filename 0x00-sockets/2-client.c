
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#ifndef __USE_XOPEN2K
#define __USE_XOPEN2K
#endif /* __USE_XOPEN2K */
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

/**
 * main - Entry point to the client server, connects to a name or IP on a
 * particular port number and exits
 * @argc: The number of arguments provided
 * @argv: The arguments provided to the program
 * Return: EXIT_FAILURE if something goes wrong, otherwise EXIT_SUCCESS
*/
int main(int argc, char const *argv[])
{
	int sock_fd = 0, port, error;
	struct sockaddr_in sock_addr, *server_addr;
	struct addrinfo *host_addr_info, hints;
	char ip_addr_buf[INET_ADDRSTRLEN];

	(void) argc;
	if (!argv[2])
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	port = atoi(argv[2]);
	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd < 0)
		ErrorAndDie("Unable to create socket");
	memset(&sock_addr, 0, sizeof(sock_addr));
	memset(&hints, 0x00, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	error = getaddrinfo(argv[1], NULL, &hints, &host_addr_info);
	if (error != 0)
		ErrorAndDie("Failed to get address info");
	server_addr = (struct sockaddr_in *)host_addr_info->ai_addr;
	inet_ntop(AF_INET, &(server_addr->sin_addr), ip_addr_buf, INET_ADDRSTRLEN);
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(port);
	/* printf("%s IP address: %s\n", argv[1], ip_addr_buf); */
	error = inet_pton(AF_INET, ip_addr_buf, &sock_addr.sin_addr);
	if (error <= 0)
		ErrorAndDie("Invalid address/Address not supported");
	if (connect(sock_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
		ErrorAndDie("Connection Failed");
	printf("Connected to %s:%s\n", argv[1], argv[2]);
	freeaddrinfo(host_addr_info);
	return (EXIT_SUCCESS);
}
