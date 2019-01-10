CC = gcc
CFLAGS = -O0 -g -Wall
LIBS = -lm

all: main check

main: access.c main.c
	$(CC) $(CFLAGS) main.c access.c $(LIBS) -o run 

check: run
	./run

clean:
	rm -f *.o main

plot:
	gnuplot runtime.gp
