#include <iostream>
#include <math.h>
#include <fstream>
#define N 1235
#define N_set 10
#define FILE_OUT "all.dat"
using namespace std;

int main(int argc, char** argv) {
	double t[N],v1[N_set][N],v2[N_set][N];
	int i=0;
	
	
	for(int ts=0; ts<N_set;ts++){
		char nome[7];
		switch(ts){
			case 0: sprintf(nome, "%s", "a1.dat"); break;
			case 1: sprintf(nome, "%s", "b1.dat"); break;
			case 2: sprintf(nome, "%s", "c1.dat"); break;
			case 3: sprintf(nome, "%s", "d1.dat"); break;
			case 4: sprintf(nome, "%s", "e1.dat"); break;	
			case 5: sprintf(nome, "%s", "f1.dat"); break;
			case 6: sprintf(nome, "%s", "g1.dat"); break;
			case 7: sprintf(nome, "%s", "h1.dat"); break;
			case 8: sprintf(nome, "%s", "i1.dat"); break;
			case 9: sprintf(nome, "%s", "j1.dat"); break;		
		}
		

		printf("\n Leggo set %s \n",nome);

		i=0;
		fstream file (nome, fstream::in);
		do{
			file >> t[i] >> v1[ts][i] >> v2[ts][i];
			//printf("%d %.9lf %.9lf %.9lf\n",ts,t[i],v1[ts][i],v2[ts][i]);
			i+=1;
			if(ts==9){printf("\n %d \n",i);}
		}while(!file.eof());
		file.close();
	}

	printf("\n Ora stampo!\n");

	FILE *file2;
	file2=fopen(FILE_OUT,"w");
	for(i=0;i<N-1;i++){
		fprintf(file2,"%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \n",t[i],v1[0][i],v2[0][i],v1[1][i],v2[1][i],v1[2][i],v2[2][i],v1[3][i],v2[3][i],v1[4][i],v2[4][i],v1[5][i],v2[5][i],v1[6][i],v2[6][i],v1[7][i],v2[7][i],v1[8][i],v2[8][i],v1[9][i],v2[9][i]);
	}
	
	fclose(file2);
}
