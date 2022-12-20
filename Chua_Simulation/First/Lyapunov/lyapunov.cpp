#include <iostream>
#include <math.h>
#include <fstream>
#define N 5000
using namespace std;

double distance(double v1[2][N], double v2[2][N], int i){
return sqrt((v1[0][i]-v1[1][i])*(v1[0][i]-v1[1][i])+(v2[0][i]-v2[1][i])*(v2[0][i]-v2[1][i]));
}

int main(int argc, char** argv) {
	double t[2][N],il[2][N],v2[2][N],v1[2][N], sum=0;
	int i=0, ii=0;
	
	//fstream file ("t_trajectories_v2_07.dat", fstream::in);
	fstream file ("t_trajectories_v2_001.dat", fstream::in);

		do{
			file >> t[0][i] >> il[0][i]>> v2[0][i] >> v1[0][i];
			//printf("i:%d t=%.5lf v1=%.5lf v2=%.5lf\n",i+1, t[0][i], v1[0][i], v2[0][i]);
			i+=1;
		}while(!file.eof()&&i<N-1);

	i=0;
	
	//fstream file2 ("t_trajectories_v12_07.dat", fstream::in);
	fstream file2 ("t_trajectories_v12_001.dat", fstream::in);
		do{
			file >> t[1][i] >> il[1][i]>> v2[1][i] >> v1[1][i];
			//printf("i:%d t=%.5lf v1=%.5lf v2=%.5lf\n",i+1, t[1][i], v1[1][i], v2[1][i]);
			i+=1;
		}while(!file2.eof()&&i<N-1);
	
	
	//----------------------------------------------- stampa su file I(V)
	FILE *file3;
	file3=fopen("t_delta.dat","w");
	for(i=2;i<N-100;i++){
		if(i<N-108){
			sum+=log(abs(distance(v1,v2,i)/(distance(v1,v2,3)-distance(v1,v2,2))));
		}
		//printf("%lf \n",sum);
		fprintf(file3,"%lf %lf\n",t[0][i],distance(v1,v2,i));
	}
	
	printf("\n Lyapunov Exponent: %d %lf \n",i,(float)1/((i-10)*(t[0][1]-t[0][0])) * sum );
	
	fclose(file3);
}
