#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

int	maxSock; // Maximum socket descriptor value
char*	msg = NULL; // Temporary storage for the message to be sent

int	clients[5000]; // Array to store client IDs
char*	clientMsgs[5000]; // Buffer for each client's messages

char	sendBuff[1001], recvBuff[1001]; // Buffers for sending and receiving messages
fd_set	readSet, writeSet, activeSet; // fd_set for select() function

// Prints error message and exits
void	error(char *s) {
	perror(s);
	exit(1);
}

// Concatenates strings, frees the original buffer, and returns the new string
char*	joinStr(char* buff, char* add) {
	int	lenBuff = buff ? strlen(buff) : 0;
	int	lenAdd = add ? strlen(add) : 0;
	char*	res = malloc(lenBuff + lenAdd + 1);
	
	if (!res)
		return 0;
	res[0] = '\0';
	if (buff) {
		strcat(res, buff);
		free(buff);
	}
	if (add)
		strcat(res, add);
	return res;
}

// Extracts a message up to a newline character
int	splitMsg(char** buff, char** msg) {
	*msg = NULL;
	if (!*buff)
		return 0;

	for (int i = 0; (*buff)[i]; i++) {
		if ((*buff)[i] == '\n') {
			char*	newBuff = calloc(strlen(*buff + i + 1) + 1, sizeof(char));
			if (!newBuff)
				return -1;
			strcpy(newBuff, *buff + i + 1);
			*msg = *buff;
			(*msg)[i + 1] = '\0';
			*buff = newBuff;
			return 1;
		}
	}
	return 0;
}

// Sends a message to all clients except the sender
void	broadcast(int fd) {
	for (int i = 3; i <= maxSock; i++) {
		if (FD_ISSET(i, &writeSet) && i != fd) {
			send(i, sendBuff, strlen(sendBuff), 0);
			if (msg)
				send(i, msg, strlen(msg), 0);
		}
	}
}

int main(int argc, char **argv) {
	if (argc != 2)
		error("Wrong number of arguments\n");

	int sock, conn, id = 0;
	struct sockaddr_in serv, cli;
	bzero(&serv, sizeof(serv));
	socklen_t cliLen = sizeof(cli);

	// Initialize server address
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serv.sin_port = htons(atoi(argv[1]));

	// Create socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		error("Fatal error\n");

	// Bind socket
	if (bind(sock, (struct sockaddr *)&serv, sizeof(serv)) < 0)
		error("Fatal error\n");

	// Listen for connections
	if (listen(sock, SOMAXCONN) < 0)
		error("Fatal error\n");

	// Initialize fd_sets
	maxSock = sock;
	FD_ZERO(&activeSet);
	FD_SET(sock, &activeSet);

	while (1) {
		readSet = writeSet = activeSet;
		// Select active sockets
		if (select(maxSock + 1, &readSet, &writeSet, NULL, NULL) <= 0)
			continue;

		// Accept new connections
		if (FD_ISSET(sock, &readSet)) {
			conn = accept(sock, (struct sockaddr *)&cli, &cliLen);
			if (conn < 0)
				error("Fatal error\n");
			FD_SET(conn, &activeSet);
			maxSock = conn > maxSock ? conn : maxSock;
			clients[conn] = id++;
			sprintf(sendBuff, "server: client %d just arrived\n", clients[conn]);
			broadcast(conn);
			clientMsgs[conn] = NULL;
		}
		// Handle data from clients
		for (int i = 3; i <= maxSock; i++) {
			if (FD_ISSET(i, &readSet) && i != sock) {
				int	rd = recv(i, recvBuff, 1000, 0);
				if (rd <= 0) {
					// Client disconnects
					FD_CLR(i, &activeSet);
					sprintf(sendBuff, "server: client %d just left\n", clients[i]);
					broadcast(i);
					free(clientMsgs[i]);
					close(i);
				} else {
					// Receive and process messages
					recvBuff[rd] = '\0';
					clientMsgs[i] = joinStr(clientMsgs[i], recvBuff);
					while (splitMsg(&clientMsgs[i], &msg)) {
						sprintf(sendBuff, "client %d: ", clients[i]);
						broadcast(i);
						free(msg); msg = NULL;
					}
				}
			}
		}
	}
	return 0;
}
