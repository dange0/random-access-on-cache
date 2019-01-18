# Random-access-on-cache
Compare the CPE cost of random access and sequential access on cache.

## Dependencies

For performance measurement, you must have the package `cpupower` installed in your machine. For installation, run the below command on Ubuntu:
```
$ sudo apt install linux-tools-common linux-tools-generic
```
and then check the other package needed (if necessary, machine wise so we can't list them here) and install them. Mostly are linux kernel tools.

We use **gnuplot** to plot the performance comparison graph. So you need it installed in your system.
```
$ sudo apt install gnuplot
```

## Usage

For basic benchmarking, run the following command. And it need the permission of sudo for locking CPU frequency:

```
$ make run
gcc -O0 -g -Wall -c cpu.c
gcc -O0 -g -Wall -c access.c
gcc -O0 -g -Wall -c main.c
gcc -O0 -g -Wall cpu.o access.o  main.o -o main -lm
[sudo] password for User:
```

## Plot 
For visualized test result, plotted with gnuplot, run the following command:
```
$ make plot
```
And the result will show in `seq.png`, `ram.png` and `seq&ram.png`

This is the example of `seq&ram.png`:

![](https://i.imgur.com/UPP2EdI.png)