CC = gcc
CFLAGS = -c -Wall


all: fmove clean

fmove: main.o
	$(CC) main.o -o fmove

main.o: main.c
	$(CC) main.c $(CFLAGS)

clean:
	rm *.o