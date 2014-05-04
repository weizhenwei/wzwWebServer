/*
 * whttp.c, source file of http operation 
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.03.12
 *
 * vim settings: set ts=4, set expandtab
 * replace tab with space: %retab!
 */

#include "whttp.h"
#include <stdio.h>
#include <string.h>

const char *hellowHTML = "HTTP/1.1 200 ok\r\n"
                                "Server: wzwWebServer0.01\r\n"
                                "Connection: close\r\n"
                                "Max-Age: 0\r\n"
                                "Expires: 0\r\n"
                                "Cache-Control: no-cache\r\n"
                                "Cache-Control: private\r\n"
                                "Pragma: no-cache\r\n"
                                "Content-type: text/html\r\n\r\n"
                                "<html>\n"
                                "<head>\n"
                                "<title>HelloHTML</title>\n"
                                "</head>"
                                "<body>\n"
                                "Hello, HTML!\n"
                                "</body>\n"
                                "</html>\n";

const char *hellowWorld = "HTTP/1.1 200 ok\r\n"
                                "Server: wzwWebServer0.01\r\n"
                                "Connection: close\r\n"
                                "Max-Age: 0\r\n"
                                "Expires: 0\r\n"
                                "Cache-Control: no-cache\r\n"
                                "Cache-Control: private\r\n"
                                "Pragma: no-cache\r\n"
                                "Content-type: text/html\r\n\r\n"
                                "<html>\n"
                                "<head>\n"
                                "<title>HelloWorld</title>\n"
                                "</head>"
                                "<body>\n"
                                "Hello, world!\n"
                                "</body>\n"
                                "</html>\n";

void sendHello(int fd, const char *msg)
{
    char reply[1024];
    int len = strlen(msg);
    sprintf(reply, msg, len);
    reply[len] = '\0';

    printf("reply to send:\n%s\n", reply);
    int sendlen = write(fd, reply, len);
    if (sendlen != len) {
        printf("send length not match\n");
        printf("expected send length:%d, actual send length:%d\n",
                len, (int)sendlen);
    } else {
        printf("send succeed client\n\n");
    }
}
