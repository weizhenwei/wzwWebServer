/*
 * wsocket.h, header file of socket operation
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.03.12
 *
 * vim settings: set ts=4, set expandtab
 * replace tab with space: %retab!
 */

#ifndef WSOCKET_H
#define WSOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>

#define BIND_PORT 8082
#define BIND_ADDR "127.0.0.1"

#define LISTEN_BACKLOG 10
#define SENDBUF 32768
#define RECVBUF 32768

#define MAX_EPOLL_EVENT 1024

#define BUFFSIZE 1024

struct sockaddr *serverAddr;
struct sockaddr *clientAddr;


static int newSocket(void);
static void closeSocket(int sockfd);

static struct sockaddr *newAddress();
static void releaseAddress(struct sockaddr *addr);
static int bindAddress(int sockfd, struct sockaddr *addr);
static int listenAddress(int sockfd);

static int acceptConnection(int sockfd, struct sockaddr *clientAddress);


static int newEpollSocket(void);
static int addSockfd(int epollfd, int fd);
static void handleEvent(int epollfd, int sockfd, struct epoll_event *events, int nevents, int *count);

int mainLoop();



#endif
