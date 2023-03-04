CC = gcc
CFLAGS = -c -Wall


all: fmove clean

fmove: main.o
	$(CC) fmove.o -o fmove

main.o: fmove.c
	$(CC) fmove.c $(CFLAGS)

clean:
	rm *.o