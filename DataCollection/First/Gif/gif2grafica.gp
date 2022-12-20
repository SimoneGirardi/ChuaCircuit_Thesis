#set datafile separator ','
set terminal gif animate delay 200
set output 'ChaosV.gif'
#set palette rgb 30,13,10
unset key
unset colorbox
set title "V_1 and V_2 waveforms" font "Helvetica,16"
set xlabel "Time [ms]" font "Helvetica,16"
set ylabel "Voltage [V]" font "Helvetica,16"
set xr [-0.005:0.005]
set yr [-2:+2]


###-------- INSERT DATA TO PLOT (.csv)
 
filename="all.dat"


do for [i=0:4] {
	plot filename u 1:2*i+2 w l lc 'red', filename u 1:2*i+3 w l lc 'blue'
}


pause -1 
