/*
 * whttp.c, source file of http operation 
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.03.12
 */

#include "whttp.h"

void sendHello(int fd)
{
    printf("reply to send:\n%s\n", hellowHTML);
    int sendlen = write(fd, hellowHTML, sizeof(hellowHTML));
    if (sendlen != sizeof(hellowHTML)) {
	printf("send length not match\n");
    } else {
	printf("send succeed client\n\n");
    }
}
