#main.cpp, entry point of the program
#
#weizhenwei <weizhenwei1988@gmail.com>
#Date: 2014.03.12
#
# Makefile variables:
# $@: object file;
# $<: first prerequisite file name;
# $?: all prerequisites that are newer than than object;
# $^: all prerequisites; 

all: webServer

CFLAGS=-ggdb3
CC=gcc

OBJECT=whttp.o wsocket.o main.o

webServer: $(OBJECT)
	$(CC) -o $@ $(CFLAGS) $^

whttp.o: whttp.c whttp.h
	$(CC) $(CFLAGS) -c $^

wsocket.o: wsocket.c wsocket.h
	$(CC) $(CFLAGS) -c $^

main.o: main.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf *.o
	rm -rf *.gch
	rm -rf webServer


