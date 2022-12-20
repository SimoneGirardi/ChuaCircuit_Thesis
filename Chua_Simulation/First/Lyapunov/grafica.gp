###################################################-------- INSERT DATA TO PLOT 
#set datafile separator ','   # uncomment for (.csv) file

filename="t_delta.dat"


###################################################----------------------------- plot0

set term qt size 750,500 position 200,0 font "Helvetica,11"
#set palette rgb 30,13,10
#unset key
unset colorbox

set title "{/Symbol d}(t)" enhanced font "Helvetica,16"
set xlabel "Time [{/Symbol m}s]" font "Helvetica,16"
set ylabel "Distance [V]" font "Helvetica,16"
set fit quiet

set xr [10:270]
#set yr [-0.8:+0.8]

f(x) = b + n*exp(x*u)
b=0.0001;
u=0.023;
n=0.001;
fit f(x) filename using ($1*1000000):2 via b,n,u

plot filename u ($1*1000000):2 w l title "Theoretical data", f(x) title "Exponential fit"

pause -1
