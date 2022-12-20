#include <iostream>
#include <math.h>
#include <fstream>
#define N 1236
#define FILE_OUT "all.dat"
using namespace std;

int main(int argc, char** argv) {
	double t[N],v1[5][N],v2[5][N];
	int i=0;
	
	
	for(int ts=0; ts<5;ts++){
		char nome[7];
		switch(ts){
			case 0: sprintf(nome, "%s", "a.dat"); break;
			case 1: sprintf(nome, "%s", "b.dat"); break;
			case 2: sprintf(nome, "%s", "c.dat"); break;
			case 3: sprintf(nome, "%s", "d.dat"); break;
			case 4: sprintf(nome, "%s", "e.dat"); break;			
		}
		
		i=0;
		fstream file (nome, fstream::in);
		do{
			file >> t[i] >> v1[ts][i] >> v2[ts][i];
			//printf("%d %.9lf %.9lf %.9lf\n",ts,t[i],v1[ts][i],v2[ts][i]);
			i+=1;
		}while(!file.eof());
		file.close();
	}

	

	FILE *file2;
	file2=fopen(FILE_OUT,"w");
	for(i=0;i<N-1;i++){
		fprintf(file2,"%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \n",t[i],v1[0][i],v2[0][i],v1[1][i],v2[1][i],v1[2][i],v2[2][i],v1[3][i],v2[3][i],v1[4][i],v2[4][i]);
	}
	
	fclose(file2);
}
