reset
set xlabel 'working set size(Bytes)'
set logscale x 2
set format x '2^{%L}
set ylabel 'cycle per element'
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'seq&ram.png'

plot "result_seq.txt" with linespoints title 'sequential' ,\
"result_ram.txt"  with linespoints title 'random'

reset
set xlabel 'working set size(Bytes)'
set logscale x 2
set format x '2^{%L}
set ylabel 'cycle per element'
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'seq.png'

plot "result_seq.txt" with linespoints title 'sequential'


reset
set xlabel 'working set size(Bytes)'
set logscale x 2
set format x '2^{%L}
set ylabel 'cycle per element'
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'ram.png'

plot "result_ram.txt"  with linespoints title 'random'