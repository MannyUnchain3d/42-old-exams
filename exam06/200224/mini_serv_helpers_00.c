#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

int	maxSock;
char*	msg = NULL;

int	clients[5000];
int	clientMsgs[5000];

char	sendBuff[1001], recvBuff[1001];
fd_set	readSet, writeSet, activeSet;

void	error(char* s) {
	perror(s);
	exit(1);
}

char*	joinStr(char* buff, char* add) {
	int	lenBuff = buff ? strlen(buff) : 0;
	int	lenAdd = add ? strlen(add) : 0;
	char*	res = malloc(lenBuff + lenAdd + 1);

	if (!res)
		return 0;
	res[0] = NULL;
	if (buff) {
		strcat(res, buff);
		free(buff);
	}
	if (add)
		strcat(res, add);
	return res;
}

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
			*msg = newBuff;
			return 1;
		}
	}
	return 0;
}

void	broadcast(int fd) {
	for (int i = 3; i <= maxSock; i++) {
		if (FD_ISSET(i, &writeSet) && i != fd) {
			send (i, sendBuff, strlen(sendBuff), 0);
			if (msg)
				send (i, msg, strlen(msg), 0);
		}
	}
}
