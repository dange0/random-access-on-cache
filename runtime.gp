reset
set ylabel 'element'
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot "result_ram.txt" with linespoints , "result_seq.txt"  with linespoints

