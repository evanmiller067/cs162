OBJECTS = main.o array.o supplied.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
CPPFLAGS = -Wall -g -std=c++11

main: main.o array.o supplied.o

main.o: array.h

supplied.o: array.h

.PHONY: clean

clean:
	rm -f main

	
