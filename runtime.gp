reset
set xlabel 'element'
set ylabel 'time'
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot "result_seq.txt" with linespoints , "result_ram.txt"  with linespoints
