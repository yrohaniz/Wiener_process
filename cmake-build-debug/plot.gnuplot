set terminal postscript eps color enhanced "Helvetica" 68
set output "Wiener_process.eps"
set size 2.2,2.2
set xrange [0:40]
set xlabel "t"
set ylabel "W_{t}" rotate by 0
set yrange [-8:8]
set style line 1 lt 0 lw 5 lc rgb '#000000' 
set style line 2 lt 1 lw 5 lc rgb '#bebebe'
set style line 3 lt 2 lw 5 lc rgb '#8b0000'
set style line 4 lt 1 lw 5 lc rgb '#c8c800'
set style line 5 lt 3 lw 5 lc rgb '#006400'
set style line 6 lt 1 lw 5 lc rgb '#0000cd'
set style line 7 lt 4 lw 5 lc rgb '#ff8c00'
set style line 8 lt 1 lw 1 lc rgb '#000000'
set mxtics
set mytics


plot "Wiener_sample" w l ls 8 notitle
