CC = gcc
CFLAGS = -O0 -g -Wall
LIBS = -lm

all: main check plot

main: access.c main.c
	$(CC) $(CFLAGS) main.c access.c $(LIBS) -o run 

check: run
	./run

clean:
	rm -f *.o run *.png *.txt

plot:
	gnuplot runtime.gp
