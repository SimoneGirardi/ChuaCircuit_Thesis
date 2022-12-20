#set datafile separator ','
set terminal gif animate delay 200
set output 'ChaosV.gif'
#set palette rgb 30,13,10
#unset key
unset colorbox
set title "V_1 and V_2 waveforms" font "Helvetica,16"
set xlabel "Time [ms]" font "Helvetica,16"
set ylabel "Voltage [V]" font "Helvetica,16"
set xr [-4:4]
set yr [-2:+2.5]


###-------- INSERT DATA TO PLOT (.csv)

filename="all.dat"


do for [i=0:7] {
	plot filename u ($1+0.055)*1000:2*i+2 w l lc 'red' title 'V_1' , filename u ($1+0.055)*1000:2*i+3 w l lc 'blue' title 'V_2'
}


pause -1 
