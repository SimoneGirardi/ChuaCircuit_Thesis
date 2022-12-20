###################################################-------- INSERT DATA TO PLOT 
#set datafile separator ','   # uncomment for (.csv) file

filename="t_i_v2_v1.dat"


###################################################----------------------------- plot0

set term qt size 750,500 position 200,0 font "Helvetica,11"
#set palette rgb 30,13,10
unset key
unset colorbox

set title "V_1 and V_2 and I_L" font "Helvetica,16"
set xlabel "V_1 [s]" font "Helvetica,16"
set ylabel "V_2 [V]" font "Helvetica,16"
set zlabel "Current [mA]" font "Helvetica,16"

#set xr [20:28]
#set yr [-0.8:+0.8]


splot filename u 4:3:($2*1000) w l



pause -1
