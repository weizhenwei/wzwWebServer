/*
 * wsocket.cpp, source file of socket operation
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.03.12
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include "wsocket.h"
#include "whttp.h"

int newSocket(void)
{
    int val = 1;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
	perror("can not create socket:");
	return -1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int));

    return sockfd;
}

void closeSocket(int sockfd)
{
    close(sockfd);
}


struct sockaddr *newAddress()
{
    struct sockaddr_in *addr =
	(struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));

    if (addr == NULL) {
	printf("malloc struct sockaddr_in error!\n");
	return NULL;
    }

    //in_addr_t bind_addr = inet_addr(BIND_ADDR); //result is network byte order;
    //network byte order
    addr->sin_family = AF_INET;
    addr->sin_port = htons(BIND_PORT);
    addr->sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    return (struct sockaddr *) addr;
}

void releaseAddress(struct sockaddr *addr)
{
    if (addr) {
	free(addr);
    }
}


int bindAddress(int sockfd, struct sockaddr *addr)
{
    int ret = bind(sockfd, addr, sizeof(struct sockaddr));
    if (ret == -1) {
	perror("bind sock addr error:");
	return -1;
    }

    return 0;
}

int listenAddress(int sockfd)
{
    int ret = listen(sockfd, LISTEN_BACKLOG);
    if (ret == -1) {
	perror("listen sock error:");
	return -1;
    }

    return 0;
}

int acceptConnection(int sockfd, struct sockaddr *clientAddress)
{
    int addrlen = sizeof(clientAddress);
    int clientfd = accept(sockfd, clientAddress, &addrlen);
    if (clientfd == -1) {
	perror("accept client sock error:");
	return -1;
    }
}


int mainLoop()
{
    int serverfd = newSocket();
    serverAddr = newAddress();
    bindAddress(serverfd, serverAddr);
    listenAddress(serverfd);

    printf("begin to work\n");
    while (1) {
	int clientfd = acceptConnection(serverfd, clientAddr);
	
	char buffer[1024];
	memset(buffer, 0, 1024);

	int readlen = read(clientfd, buffer, 1024);
	if (readlen == -1) {
	    perror("read from client error:");
	    break;
	}

	printf("read from client:\n%s\n", buffer);

	sendHello(clientfd);
    }

    closeSocket(serverfd);
    releaseAddress(serverAddr);
}

