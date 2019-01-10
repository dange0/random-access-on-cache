all: main	
	gcc main.c -o main	
plot:
	gnuplot runtime.gp
