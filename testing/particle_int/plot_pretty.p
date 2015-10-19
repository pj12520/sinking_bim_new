#Gnuplot script to plot data about the test regarding interval density

set terminal postscript color

set xlabel 'Number of intervals' font "Times-Roman, 25"

set ylabel 'Fractional error on terminal velocity' font "Times-Roman, 25"

#Oblate spheroid

set output 'int_test.eps'

set key font "Times-Roman, 25"

plot 'oblate/int_test.dat' u 2:(($5 + 0.5523)/0.5523) title 'R = 0.5' ps 2, 'sphere/int_test.dat' u 2:($5 + 1) title 'R = 1' ps 2, 'prolate/int_test.dat' u 2:(($5 + 1.6612)/1.6612) title 'R = 2' ps 2