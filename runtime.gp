reset
set xlabel 'element'
set ylabel 'time'
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot "seq_access" with linespoints , "random_access"  with linespoints

