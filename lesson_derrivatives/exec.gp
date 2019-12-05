set grid
plot [0:2*pi] sin(x)
replot [0:2*pi] cos(x)
replot "data.dat" every ::1 using 1:2 with lines title "calc sin(x)"
replot "data.dat" every ::1 using 1:3 with lines title "calc sin'(x)"
