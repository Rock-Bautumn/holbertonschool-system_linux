#include "server.h"


/* port 0 means any port the OS chooses */
#define PORT 8080

/*
 * INADDR_ANY means use any network interface the OS chooses,
 * this is (usually) 0
 */
#define IN_ADDR INADDR_ANY

/* set the maximum number of connections that can wait to be connected */
#define MAX_BACKLOG 32

/**
 * create_socket - Creates a configured TCP/IP socket file descriptor
 * @sock_addr: Pointer to the socket address info struct
 * Return: The file descriptor of the new socket
 */

int create_socket(struct sockaddr_in *sock_addr)
{
	int sock_fd = 0;

	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock_fd < 0)
		ErrorAndDie("Cannot create socket");
	memset((char *)sock_addr, 0, sizeof(*sock_addr));
	sock_addr->sin_family = AF_INET;
	sock_addr->sin_addr.s_addr = htonl(IN_ADDR);
	sock_addr->sin_port = htons(PORT);
	return (sock_fd);
}

/**
 * replyToClient - Send a reply to the client
 * @sock_fd: The file descriptor of the socket connection with the client
 * @msg: The message to send to the client
 * Return: void
 */

void replyToClient(int sock_fd, char *msg)
{
	send(sock_fd, msg, strlen(msg), MSG_NOSIGNAL);
}

/**
 * printOutput - Print the expected output from the HTTP request
 * @head: The head node for the linked list that stores the parsed query string
 * @sock_fd: The file descriptor for the client socket connection
 * @client_ip: The IP address string of the connected client (ex. "1.2.3.4")
 * @buffer: The raw HTTP request data string
 * Return: void
 */

void printOutput(ll_tdnode **tdhead, int sock_fd, char *client_ip, char *buffer)
{
	char **line, **http_info, *path, *dataString, *headerString, *json;
	ll_node *headerList = NULL;
	size_t jsonLen = 0;

	line = ndsplitter(buffer, "\n");
	http_info = ndsplitter(line[0], " ");
	path = extractPathAsCopy(line[0]);
	printf("%s %s %s -> ", client_ip, http_info[0], path);
	if (strcmp(path, "/todos") != 0 || strcmp(http_info[0], "POST") != 0)
	{
		httpToClient(sock_fd, 404);
		return;
	}
	printf("buffer is %s\n", buffer);
	headerString = strdup(strstr(buffer, "\n") + 1);
	headerList = parseHeaderString(&headerList, headerString);
	if (!listHasKey(headerList, "Content-Length"))
	{
		httpToClient(sock_fd, 411);
		return;
	}
	if (strncmp(http_info[0], "POST", 4) == 0)
	{
		dataString = strdup(strstr(buffer, "\r\n\r\n") + 4);
		if (parseTDQueryString(tdhead, dataString) < 0)
		{
			httpToClient(sock_fd, 422);
			return;
		}
		jsonLen = jsonLength(lastTDNode(tdhead));
		json = malloc(jsonLen + 1);
		dbprintf("jsonLen = %lu\n", jsonLen);
		jsonifyList(json, jsonLen + 1, lastTDNode(tdhead));
		generateAndSendResponse(sock_fd, 201, jsonLen, json);
	}
	free(line), free(http_info), free(path), free(headerString);
	headerString = NULL;
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
	ll_tdnode *tdhead = NULL;

	sock_fd = create_socket(&sock_addr);
	if (bind(sock_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
		ErrorAndDie("Failed to bind to socket");
	if (listen(sock_fd, MAX_BACKLOG) < 0)
		ErrorAndDie("Failed to listen to the socket");
	printf("Server listening on port %d\n", ntohs(sock_addr.sin_port));
	while (true)
	{
		new_sock_fd = accept(sock_fd, (struct sockaddr *)&sock_addr,
				     (socklen_t *)&addrlen);
		if (new_sock_fd < 0)
			ErrorAndDie("Unable to accept the connection");
		if (getpeername(new_sock_fd,
				(struct sockaddr *)&new_sock_addr,
				(socklen_t *)&addrlen) < 0)
			ErrorAndDie("Unable to get peer name");
		valread = read(new_sock_fd, buffer, 30000);
		if (valread == -1)
			ErrorAndDie("Unable to read socket data from client");
		printOutput(&tdhead, new_sock_fd,
			    inet_ntoa(new_sock_addr.sin_addr), buffer);
		memset(buffer, '\0', 30000);
		fflush(stdout);
		close(new_sock_fd);
	}
	close(sock_fd);
	return (EXIT_SUCCESS);
}
