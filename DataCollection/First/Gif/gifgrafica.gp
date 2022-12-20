#set datafile separator ','
set terminal gif animate delay 200
set output 'Chaos.gif'
#set palette rgb 30,13,10
unset key
unset colorbox
set title "XY V_1 and V_2 " font "Helvetica,16"
set xlabel "V_1 [V]" font "Helvetica,16"
set ylabel "V_2 [V]" font "Helvetica,16"
set xr [-2:2]
set yr [-1:+1]


###-------- INSERT DATA TO PLOT (.csv)

filename="all.dat"


do for [i=0:4] {
	plot filename u 2*i+2:2*i+3 w l lc 'purple'
	#plot filename u 2*i+3:2*i+2 w l lc 'purple'
}


pause -1 
