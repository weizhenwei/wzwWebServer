/*
 * whttp.h, header file of http operation 
 *
 * weizhenwei <weizhenwei1988@gmail.com>
 * Date: 2014.03.12
 */

#ifndef WHTTP_H
#define WHTTP_H

static const char *hellowHTML = "HTTP/1.1 200 ok\r\n"
                                "Server: wzwWebServer0.01\r\n"
				"Connection: close\r\n"
				//"Max-Age: 0\r\n"
				//"Expires: 0\r\n"
				//"Cache-Control: no-cache\r\n"
				//"Cache-Control: private\r\n"
				//"Pragma: no-cache\r\n"
				"Content-type: text/html\r\n\r\n"
				"<html>\n"
				"<head>\n"
				"<title>Hello</title>\n"
				"</head>"
				"<body>\n"
				"Hello, world!\n"
				"</body>\n"
				"</html>\n";

void sendHello(int fd);

#endif
