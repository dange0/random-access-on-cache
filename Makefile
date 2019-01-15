CC = gcc
CFLAGS = -O0 -g -Wall -m32
LIBS = -lm

all: ulimit main check plot

ulimit:
	ulimit -s unlimited

main: *.c
	$(CC) $(CFLAGS) *.c $(LIBS) -o run 

check: run
	./run

clean:
	rm -f *.o run *.png *.txt

plot:
	gnuplot runtime.gp
