CC:=gcc
exe:=main
obj:=main.o access.o 

all:$(obj)
	$(CC) -o $(exe) $(obj)  
%.o:%.c
	$(CC) -c $^ -o $@

.PHONY:clean
clean:
	rm -rf $(obj) $(exe)
plot:
	gnuplot runtime.gp


