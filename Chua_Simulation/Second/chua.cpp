#include <iostream>
#include <math.h>
#define a2 -1.0/2200.0
#define b2 1.0/220
#define e2 4.5
#define a1 -1.0/3300.0
#define b1 1.0/22000
#define e1 0.55
#define l 0.020
#define c1 0.000000010
#define c2 0.000000100
#define rg 1000.0
#define cg 0.000000020
#define tau rg*cg
#define imax 10000


double function(int z, double y[3], double r){
	double i3=0;
	double ga=(a1+a2), gb=(b1+a2), gc=(b2+b1);

	switch(z){
		case 0: //funzione per il calcolo di I_L
			//2*y[0]+1;			
			return (-1/l)*y[1];
		break;

		case 1: //funzione per il calcolo di V_2
			//y[1]*y[1];
			return (1/c2)*y[0] - 1/(r*c2)*(y[1]-y[2]);
		break;

		case 2: //funzione per il calcolo di V_1

			if(y[2]<=-e2){ 
				i3= gc*y[2] + ((gc-gb)*e2+(gb-ga)*e1); 
			}if(y[2]>-e2 && y[2]<=-e1){ 
				i3= gb*y[2] + (gb-ga)*e1; 
			}if(y[2]>-e1 && y[2]<e1){ 
				i3= ga*y[2]; 
			}if(y[2]>=e1 && y[2]<e2){ 
				i3= gb*y[2] - (gb-ga)*e1;
			}if(y[2]>=e2){ 
				i3= gc*y[2] - ((gc-gb)*e2+(gb-ga)*e1); 	
			}

			return (1/(c1*r))*(y[1]-y[2]) - i3/c1;
		break;

		case 3:
			if(y[2]<=-e2){ 
				i3= gc*y[2] + ((gc-gb)*e2+(gb-ga)*e1); 
			}if(y[2]>-e2 && y[2]<=-e1){ 
				i3= gb*y[2] + (gb-ga)*e1; 
			}if(y[2]>-e1 && y[2]<e1){ 
				i3= ga*y[2]; 
			}if(y[2]>=e1 && y[2]<e2){ 
				i3= gb*y[2] - (gb-ga)*e1;
			}if(y[2]>=e2){ 
				i3= gc*y[2] - ((gc-gb)*e2+(gb-ga)*e1); 	
			}
		return i3;
		break;
	}
}

double function2(int z, double y[3], double r){
	double i3=0;
	double ga=(a1+a2), gb=(b1+a2), gc=(b2+b1);

	switch(z){
		case 0: //funzione per il calcolo di I_L
			//2*y[0]+1;			
			return (1/l)*y[1];
		break;

		case 1: //funzione per il calcolo di V_2
			//y[1]*y[1];
			return (1/c2)*y[0] - 1/(r*c2)*(y[1]-y[2]);
		break;

		case 2: //funzione per il calcolo di V_1

			if(y[2]<=-e2){ 
				i3= gc*y[2] + ((gc-gb)*e2+(gb-ga)*e1); 
			}if(y[2]>-e2 && y[2]<=-e1){ 
				i3= gb*y[2] + (gb-ga)*e1; 
			}if(y[2]>-e1 && y[2]<e1){ 
				i3= ga*y[2]; 
			}if(y[2]>=e1 && y[2]<e2){ 
				i3= gb*y[2] - (gb-ga)*e1;
			}if(y[2]>=e2){ 
				i3= gc*y[2] - ((gc-gb)*e2+(gb-ga)*e1); 	
			}

			return (1/(c1*r))*(y[1]-y[2]) - i3/c1;
		break;

		case 3:
			if(y[2]<=-e2){ 
				i3= gc*y[2] + ((gc-gb)*e2+(gb-ga)*e1); 
			}if(y[2]>-e2 && y[2]<=-e1){ 
				i3= gb*y[2] + (gb-ga)*e1; 
			}if(y[2]>-e1 && y[2]<e1){ 
				i3= ga*y[2]; 
			}if(y[2]>=e1 && y[2]<e2){ 
				i3= gb*y[2] - (gb-ga)*e1;
			}if(y[2]>=e2){ 
				i3= gc*y[2] - ((gc-gb)*e2+(gb-ga)*e1); 	
			}
		return i3;
		break;
	}
}

double integrate(double i_saved[imax], int itop , double dt){
	double f=0;
	int j=0;
	if(itop==0 || itop==1){
		return 0;
	}else{
		for(j=0;j<itop-1;j++){

  f+= (double)(i_saved[j]*exp(-((itop-j)*dt)/(2*tau)) + i_saved[j+1]*exp(-((itop-j+1)*dt)/(2*tau)))*dt/2;
  //f+= (double)(i_saved[j] + i_saved[j+1])*dt/2;
		
		}
		if(1/*f>0.00001*/){printf("%lf\n",f);}
		return f;
	}

}

int main(int argc, char** argv) {
	double t, dt, tmin=0, tmax=0.03;
	double y[3],y1[3],y2[3],y3[3],k1[3],k2[3],k3[3],k4[3];

	double r=0;

	r=1662;              // default

	//r=1230.000;	     // dati tesi at
	r=1650.000;
	//r=1660.0;            
	//r=1660.003;	     // QUA PARTE IL CHAOS BEHAVIOUR
	//r=1660.700;	     // dati tesi dt
	//r=1662.000;	
	//r=1750.000;
	//r=1849.00;         // 1849-1851 QUA LE ORBITE SONO PERIODICHE (se viste da t>0.022)!!
	//r=1950.00;
	//r=2010.000;
	//r=2015.000;
	//r=2025;
	//r=2035.000;        // DOUBLE SCROLL
	//r=2050.000;        // dati tesi gt
	//r=2080.000;	     // QUA INIZIA A DIVENTARE DISSIPATIVO FINO A MORIRE
	//r=2500.00;	


	double y0=0.001;
	
	int i=0;
	double i_saved[imax+1];
	dt=(float)(tmax-tmin)/imax;
	
	//----------------------------------------------- stampa su file I(V)
	FILE *file;
	file=fopen("t_i_v2_v1.dat","w");

	y[0]=0.0;
	y[1]=y0;
	y[2]=y0;	

	for(i=0;i<=imax;i++){
		t=tmin+dt*i;
		
		if(abs(y[1]) > 2.3 && (y[1]-y[0]*rg)>2.3 ){

			//y[0]=((2*y[1])/(3*rg)-(1/(6*tau))*integrate(i_saved,i,dt))*10;
			//y[0]=(2*y[1])/(3*rg);
			y[0]=(y[1])/(rg);		
			
			for(int ii=0;ii<3;ii++){
				k1[ii]=function(ii,y,r);
			}


			for(int ii=1;ii<3;ii++){
				y1[ii]=y[ii]+dt/2*k1[ii];
			}
			for(int ii=1;ii<3;ii++){
				k2[ii]=function(ii,y1,r);
			}


			for(int ii=1;ii<3;ii++){
				y2[ii]=y[ii]+dt/2*k2[ii];
			}
			for(int ii=1;ii<3;ii++){
				k3[ii]=function(ii,y2,r);
			}

	
			for(int ii=1;ii<3;ii++){
				y3[ii]=y[ii]+dt*k3[ii];
			}
			for(int ii=1;ii<3;ii++){
				k4[ii]=function(ii,y3,r);
			}
	
			for(int ii=1;ii<3;ii++){
				y[ii]+=dt/6*(k1[ii]+2*k2[ii]+2*k3[ii]+k4[ii]);
			}

		}if(/*abs(y[1]) > 2.3 && (y[1]-y[0]*rg)<2.3*/0 ){

			for(int ii=0;ii<3;ii++){
				k1[ii]=function2(ii,y,r);
			}


			for(int ii=0;ii<3;ii++){
				y1[ii]=y[ii]+dt/2*k1[ii];
			}
			for(int ii=0;ii<3;ii++){
				k2[ii]=function2(ii,y1,r);
			}

	
			for(int ii=0;ii<3;ii++){
				y2[ii]=y[ii]+dt/2*k2[ii];
			}
			for(int ii=0;ii<3;ii++){
				k3[ii]=function2(ii,y2,r);
			}

	
			for(int ii=0;ii<3;ii++){
				y3[ii]=y[ii]+dt*k3[ii];
			}
			for(int ii=0;ii<3;ii++){
				k4[ii]=function2(ii,y3,r);
			}

			for(int ii=0;ii<3;ii++){
				y[ii]+=dt/6*(k1[ii]+2*k2[ii]+2*k3[ii]+k4[ii]);
			}

		}else{		
			
			for(int ii=0;ii<3;ii++){
				k1[ii]=function(ii,y,r);
			}


			for(int ii=0;ii<3;ii++){
				y1[ii]=y[ii]+dt/2*k1[ii];
			}
			for(int ii=0;ii<3;ii++){
				k2[ii]=function(ii,y1,r);
			}

	
			for(int ii=0;ii<3;ii++){
				y2[ii]=y[ii]+dt/2*k2[ii];
			}
			for(int ii=0;ii<3;ii++){
				k3[ii]=function(ii,y2,r);
			}

	
			for(int ii=0;ii<3;ii++){
				y3[ii]=y[ii]+dt*k3[ii];
			}
			for(int ii=0;ii<3;ii++){
				k4[ii]=function(ii,y3,r);
			}

			for(int ii=0;ii<3;ii++){
				y[ii]+=dt/6*(k1[ii]+2*k2[ii]+2*k3[ii]+k4[ii]);
			}
		
		}
		
		i_saved[i]=y[0];
		if(t>0.004 /*&& t<0.00669*/){fprintf(file,"%lf %lf %lf %lf\n",t,y[0],y[1],y[2]);}
		//if(1){fprintf(file,"%lf %lf %lf %lf\n",t,y[0],y[1],y[2]);}
		
		//fprintf(file,"%lf %lf %lf\n",t,y[0],y[1]);
	}

	//printf("%lf",tau);
	//for(i=0;i<=imax;i++){printf("\n %lf",i_saved[i]);}
	
	fclose(file);

	printf("\n Resistance R= %lf \n\n",r);
}
