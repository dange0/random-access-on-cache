CC = gcc
CFLAGS = -O0 -g -Wall
LIBS = -lm

all: main

main: access.c main.c
	$(CC) $(CFLAGS) $(LIBS) -o main main.c access.c

check: main
	./main

clean:
	rm -f *.o main

plot:
	gnuplot runtime.gp
