set terminal postscript enhanced

set key top right
set key font "Times-Roman, 25"
set output 'pretty_Happel.eps'

set logscale x

set xlabel 'R' font "Times-Roman, 25"
set ylabel 'U_{s}' font "Times-Roman, 25"
set xrange[0.1:10]
set yrange[-4:0]

plot 'Happel.dat' u 1:2 w lines title 'Analytical', 'output.dat' u 1:5 w points title 'Model Output'