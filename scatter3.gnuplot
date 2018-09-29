set term png
set key font ",10"
set title font ",10"
set style data points
set key left top
set output "scatter.png"
set title "Scatter Plot of the Actual Time Efficiency of Euclid's Algorithm"
set grid
set pointsize
plot "timeeuclid.txt" title "Real Time Efficiency" with points lt 2 pt 3
quit
