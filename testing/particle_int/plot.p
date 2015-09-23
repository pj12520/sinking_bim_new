#Gnuplot script to plot data about the test regarding interval density

set terminal postscript color

set xlabel 'Number of intervals'

set ylabel 'Fractional error on terminal velocity'

#Oblate spheroid

set output 'int_test.eps'

plot 'oblate/int_test.dat' u 2:(($5 + 0.5523)/0.5523) title 'R = 0.5', 'sphere/int_test.dat' u 2:($5 + 1) title 'R = 1', 'prolate/int_test.dat' u 2:(($5 + 1.6612)/1.6612) title 'R = 2'