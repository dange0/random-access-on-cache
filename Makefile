CC = gcc
CFLAGS = -O0 -g -Wall
LIBS = -lm

all: ulimit main check plot

ulimit:
	ulimit -s unlimited

main: access.c main.c cpu.c
	$(CC) $(CFLAGS) main.c cpu.c access.c $(LIBS) -o run 

check: run
	./run

clean:
	rm -f *.o run *.png *.txt

plot:
	gnuplot runtime.gp
