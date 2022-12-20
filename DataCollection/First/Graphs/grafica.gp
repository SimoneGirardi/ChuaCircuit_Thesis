
###################################################-------- INSERT DATA TO PLOT 
#set datafile separator ','   # uncomment for (.csv) file

filename="e.dat"


###################################################----------------------------- plot0

set term qt size 750,500 font "Helvetica,11"
#set palette rgb 30,13,10
unset key
unset colorbox
set title "XY V_1 and V_2 " font "Helvetica,16"
set xlabel "V_1 [V]" font "Helvetica,16"
set ylabel "V_2 [V]" font "Helvetica,16"
set xr [-1:1]
set yr [-2:+2]



plot filename u ($3):2 w l lc 'purple'




###################################################---------------------------- plot1


set term qt 1 size 750,500 font "Helvetica,11"
set key
set title "V_1 and V_2 " font "Helvetica,16"
set xlabel "Time [ms]" font "Helvetica,16"
set ylabel "V_1 [V]" font "Helvetica,16"
set y2label "V_2 [V]" font "Helvetica,16"
set y2tics
set xr [-4:4]
set yr [-2:+2.5]
set y2r [-2:+2.5]



plot filename u ($1*1000):2 axis x1y1 w l lc 'blue' title "V_1", filename u ($1*1000):3 axis x1y2 w l lc 'red' title "V_2"

pause -1
