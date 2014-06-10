CC=gcc
CFLAGS=-O2 -g -Wall
GTK3LIB=$(shell pkg-config --cflags --libs gtk+-3.0)

all:
	$(CC) $(CFLAGS) morse.c -c
	$(CC) $(CFLAGS) $(GTK3LIB) morse.o MorseCodeGUI.c -o Main

clean:
	rm -f *.o *.out Main
