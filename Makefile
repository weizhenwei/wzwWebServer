all: webServer

CFLAGS=-ggdb3

webServer: whttp.c wsocket.c main.c
	gcc -o $@ ${CFLAGS} $^

#whttp.o: whttp.c
#	gcc ${CFLAGS} $^
#	#gcc ${CFLAGS} $^ -c $@ 
#
#wsocket.o: wsocket.c wsocket.h
#	gcc -c $@ ${CFLAGS} $^

clean:
	rm -rf *.o
	rm -rf webServer


