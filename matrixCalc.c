#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NMAX 4

int main(){
	int i,j,k,ip,jp,kp;
	double mij;
	double mat[NMAX][NMAX+1]={
			           {1,-1,2,-1,-8},
			           {2,-2,3,-3,-20},
			           {1,1,1,0,-2},
			           {1,-1,4,3,4}
			          };
			         
	for(i=0;i<NMAX;i++)
	{
		for(j=0;j<NMAX+1;j++)
		{
			printf("%7.2lf ",mat[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<NMAX-1;i++){
		for(j=i+1;j<NMAX;j++){
			if(fabs(mat[j][i]) > fabs(mat[i][i])){
				for(int x=0;x<NMAX;x++){
					double temp=mat[x][i];
					mat[x][i]=mat[x][j];
					mat[x][j]=temp;
				}
				break;
			}
		}
	
		for(j=i+1;j<NMAX;j++){
			mij=mat[j][i]/mat[i][i];
			for(k=i;k<NMAX+1;k++){
				mat[j][k]=mat[j][k]-mij*mat[i][k];
			}	
		}
		printf("Round= %d\n",i+1);
		
		
		
		for(ip=0;ip<NMAX;ip++)
	{
		for(jp=0;jp<NMAX+1;jp++)
		{
			printf("%7.2lf ",mat[ip][jp]);
		}
		printf("\n");
	}
	}
	

	return 0;
}
