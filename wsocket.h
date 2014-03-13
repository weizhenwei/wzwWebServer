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
#include <unistd.h>

#define BIND_PORT 8082
#define BIND_ADDR "127.0.0.1"

#define LISTEN_BACKLOG 10

struct sockaddr *serverAddr;
struct sockaddr *clientAddr;


static int newSocket(void);
static void closeSocket(int sockfd);

static struct sockaddr *newAddress();
static void releaseAddress(struct sockaddr *addr);

static int bindAddress(int sockfd, struct sockaddr *addr);

static int listenAddress(int sockfd);

static int acceptConnection(int sockfd, struct sockaddr *clientAddress);

int mainLoop();



#endif
