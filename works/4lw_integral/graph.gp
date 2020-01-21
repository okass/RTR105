set grid
set xrange[-5:2]
f(x) = (1-x) * exp(-x)

filter(x,min,max) = (x > min && x < max) ? x : 1/0
plot [-5:2] '+' using (filter($1, -5, 2)):(f($1)) with filledcurves x1 notitle,\
'' using (filter($1, -5, 2)):(f($1)) with lines title 'f(x)'