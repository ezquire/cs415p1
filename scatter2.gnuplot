set term png
set key font ",10"
set title font ",10"
set style data points
set key left top
set output "scatter.png"
set title "Scatter Plot of the Worst Case Efficiency of Euclid's Algorithm"
set grid
set pointsize
plot "euclid.txt" title "Euclid's - upper bound roughly 47" with points lt 2 pt 3
quit