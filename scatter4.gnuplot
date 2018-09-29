set term png
set key font ",10"
set title font ",10"
set style data points
set key left top
set output "scatterSieve.png"
set title "Scatter Plot of the Average Efficiency of Euclid's and Consecutive Integer Checking"
set grid
set pointsize
plot "timeSieve.txt" title "Efficiency of Sieve Algorithm" with points lt 2 pt 3
quit