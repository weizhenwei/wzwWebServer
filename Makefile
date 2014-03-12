all: webServer

CFLAGS=-ggdb3

webServer:
	gcc -o $@ main.c

clean:
	rm -rf webServer


