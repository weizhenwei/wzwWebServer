/*
 * whttp.h, header file of http operation 
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.03.12
 *
 * vim settings: set ts=4, set expandtab
 * replace tab with space: %retab!
 */

#ifndef WHTTP_H
#define WHTTP_H

extern const char *hellowHTML;
extern const char *hellowWorld;

void sendHello(int fd, const char *msg);

#endif
