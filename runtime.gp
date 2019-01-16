reset
set xlabel 'element size (2^x)'
set ylabel 'cycle per element'
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot "result_seq.txt" with linespoints , "result_ram.txt"  with linespoints
