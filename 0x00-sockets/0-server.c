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
 * main - Entry point the server program
 * Return: EXIT_SUCCESS on success (never), EXIT_FAILURE when failure
*/
int main(void)
{
	int sock_fd;
	struct sockaddr_in sock_addr;

	/* create the socket and save its file descriptor to use later */

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (sock_fd < 0)
	{
		perror("Cannot create socket");
		return (EXIT_FAILURE);
	}
	/* zero out the address struct before we use it */
	memset((char *) &sock_addr, 0, sizeof(sock_addr));
	/* set up the address struct */
	/* set the family/domain to AF_INET since we are using IPv4 networking */
	sock_addr.sin_family = AF_INET;
	/* set the network interface to listen on */
	sock_addr.sin_addr.s_addr = htonl(IN_ADDR);
	/* set the port to listen on */
	sock_addr.sin_port = htons(PORT);
	/* bind the socket to the port and interface */
	if (bind(sock_fd, (struct sockaddr *) &sock_addr, sizeof(sock_addr))
	< 0)
	{
		perror("failed to bind to socket");
		return (EXIT_FAILURE);
	}
	/* start listening to the socket */
	if (listen(sock_fd, MAX_BACKLOG) < 0)
	{
		perror("failed to listen to the socket");
		return (EXIT_FAILURE);
	}
	printf("Listening on port %d...\n", ntohs(sock_addr.sin_port));
	while (true)
		;
	return (EXIT_SUCCESS);
}
