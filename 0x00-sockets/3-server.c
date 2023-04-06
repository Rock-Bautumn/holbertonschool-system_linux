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

/* port 0 means any port the OS chooses */
#define PORT 12345

/*
* INADDR_ANY means use any network interface the OS chooses,
* this is (usually) 0
*/
#define IN_ADDR INADDR_ANY

/* set the maximum number of connections that can wait to be connected */
#define MAX_BACKLOG 32

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
 * main - Entry point the server program
 * Return: EXIT_SUCCESS on success (never), EXIT_FAILURE when failure
*/
int main(void)
{
	struct sockaddr_in sock_addr, new_sock_addr;
	int sock_fd, new_sock_fd, addrlen = sizeof(sock_addr);
	char buffer[30000] = {0};
	ssize_t valread = 0;

	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd < 0)
		ErrorAndDie("Cannot create socket");
	memset((char *) &sock_addr, 0, sizeof(sock_addr));
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_addr.s_addr = htonl(IN_ADDR);
	sock_addr.sin_port = htons(PORT);
	if (bind(sock_fd, (struct sockaddr *) &sock_addr, sizeof(sock_addr))
	< 0)
		ErrorAndDie("Failed to bind to socket");
	if (listen(sock_fd, MAX_BACKLOG) < 0)
		ErrorAndDie("Failed to listen to the socket");
	printf("Server listening on port %d\n", ntohs(sock_addr.sin_port));
	while (true)
	{
		new_sock_fd = accept(sock_fd, (struct sockaddr *) &sock_addr,
			(socklen_t *) &addrlen);
		if (new_sock_fd < 0)
			ErrorAndDie("Unable to accept the connection");
		if (getpeername(new_sock_fd,
			(struct sockaddr *) &new_sock_addr,
			(socklen_t *) &addrlen) < 0)
			ErrorAndDie("Unable to get peer name");
		printf("Client connected: %s\n", inet_ntoa(new_sock_addr.sin_addr));
		valread = read(new_sock_fd , buffer, 30000);
		if (valread == -1)
			ErrorAndDie("Unable to read socket data from client");
		printf("Message received: \"%s\"\n", buffer);
		close(new_sock_fd);
		break;
	}
	close(sock_fd);
	return (EXIT_SUCCESS);
}
