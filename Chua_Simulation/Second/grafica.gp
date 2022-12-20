###################################################-------- INSERT DATA TO PLOT 
#set datafile separator ','   # uncomment for (.csv) file

filename="t_i_v2_v1.dat"


###################################################----------------------------- plot0

set term qt size 750,500 position 200,0 font "Helvetica,11"
#set palette rgb 30,13,10
#unset key
unset colorbox

set title "V_1 and V_2" font "Helvetica,16"
set xlabel "Time [s]" font "Helvetica,16"
set ylabel "Voltage [V]" font "Helvetica,16"

#set xr [20:28]
#set yr [-0.8:+0.8]


#f(x) = 1.5*exp(2*x-2) - 0.5
#g(x) = -1/x

plot filename u ($1*1000):3 w l title "V_{2}" lc 'red', filename u ($1*1000):4 w l lc 'blue' title "V_{1}"


###################################################--------------------------- plot1


set term qt 1 size 750,500 position 970,0 font "Helvetica,11"

unset key
set title "XY V_1 and V_2" font "Helvetica,16"
set xlabel "V_1 [V]" font "Helvetica,16"
set ylabel "V_2 [V]" font "Helvetica,16"
unset xr
unset yr

set xr [-6:6]
set yr [-6:+6]

plot filename u 4:3 w l

pause -1
