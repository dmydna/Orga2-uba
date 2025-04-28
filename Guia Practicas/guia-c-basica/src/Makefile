CC = gcc
CFLAGS = -Wall -Wextra -pedantic

all: main

main: main.o funciones.o
	$(CC) $(CFLAGS) -o main main.o funciones.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c -o funciones.o

clean:
	rm -f *.o main

.PHONY: all clean
