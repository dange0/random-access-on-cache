CC = gcc
CFLAGS = -O0 -g -Wall
LIBS = -lm
EXEC = main
OBJS = cpu.o access.o 
CPU_FREQ = sudo cpupower frequency-set -g
STACK_SIZE = ulimit -s unlimited

GIT_HOOKS := .git/hooks/applied
all: $(GIT_HOOKS) $(EXEC)

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo

.PHONY: default plot compare all clean

$(EXEC): $(OBJS) $(EXEC).o
	$(CC) $(CFLAGS) $(OBJS) $(EXEC).o -o $@ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

boost:
	@$(CPU_FREQ) performance > /dev/null
	@sleep 1


recover:
	@$(CPU_FREQ) powersave > /dev/null
	@sleep 1

run: $(EXEC) boost
	./$(EXEC)
	@$(MAKE) -s recover

clean:
	rm -f *.o run *.png *.txt

plot:
	gnuplot runtime.gp
