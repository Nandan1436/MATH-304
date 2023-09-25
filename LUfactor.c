#include <stdio.h>
#include <math.h>

#define ROW 3

double L[ROW][ROW];
double U[ROW][ROW];
double sol[ROW][ROW+1];
double D[ROW][ROW];
double Ad[ROW][ROW];

void printMatrix(double mat[ROW][ROW])
{
	for(int i=0;i<ROW;i++){
		for(int j=0;j<ROW;j++){
			printf("%0.2lf  ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void LU_factorization(double mat[ROW][ROW])
{
	int row,col;
	
	for(row=0;row<ROW;row++){
		for(col=0;col<ROW;col++){
			U[row][col]=mat[row][col];
		}
	}
	
	for(row=0;row<ROW;row++){
		for(col=0;col<ROW;col++){
			if(row==col)L[row][col]=1;
			else L[row][col]=0;	
		}
	}
	
	for(col=0;col<ROW;col++){
		for(row=col+1;row<ROW;row++){
			double factor=U[row][col]/U[col][col];
			for(int i=0;i<ROW;i++){
				U[row][i]-=factor*U[col][i];
			}
			L[row][col]=factor;
		}
	}
}

void checkLU(double mat1[ROW][ROW],double mat2[ROW][ROW])
{
	double check[ROW][ROW];
	int i,j,k;
	for(i=0;i<ROW;i++){
		for(j=0;j<ROW;j++){
			for(k=0;k<ROW;k++){
				check[i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
	}
	printMatrix(check);
}

void solution()
{
	int numRow=ROW;
	int numCol1=ROW;
	int numCol2=ROW+1;
	int row,col;
	for(col=0;col<numCol1;col++){
		for(row=col+1;row<numRow;row++){
			double factor=sol[row][col]/sol[col][col];
			for(int i=0;i<numCol2;i++){
				sol[row][i]-=factor*sol[col][i];
			}
		}
	}
	for(col=numCol1-1;col>=0;col--){
		for(row=col-1;row>=0;row--){
			double factor=sol[row][col]/sol[col][col];
			for(int i=0;i<numCol2;i++){
				sol[row][i]-=factor*sol[col][i];
			}
		}
	}
	col=0;
	for(row=0;row<ROW;row++){
		double factor=sol[col][col];
		for(int j=0;j<numCol2;j++){
			sol[row][j]/=factor;
		}
		col++;
	}
	
}

int main()
{
	double mat[ROW][ROW]=
	 {{4,1,1},
	  {2,5,2},
	  {1,2,4},
	 };
	double val[ROW]={8,3,11};
	 LU_factorization(mat);	
	 
	 printf("Given matrix: \n");
	 printMatrix(mat);
	 /*printf("L: \n");
	 printMatrix(L);
	 printf("U: \n");
	 printMatrix(U);
	 printf("After L*U: \n");
	 checkLU(L,U);*/
	 
	 for(int i=0;i<ROW;i++){
	 	for(int j=0;j<ROW+1;j++){
	 		if(j==ROW)sol[i][j]=val[i];
	 		else sol[i][j]=L[i][j];
	 	}
	 }
	 
	 /*for(int i=0;i<ROW;i++){
	 	for(int j=0;j<ROW+1;j++){
	 		printf("%0.2lf ",sol[i][j]);
	 	}
	 	printf("\n");
	 }*/
	 
	 solution();
	 
	 for(int i=0;i<ROW;i++){
	 	for(int j=0;j<ROW+1;j++){
	 		if(j==ROW)sol[i][j]=sol[i][ROW];
	 		else sol[i][j]=U[i][j];
	 	}
	 }
	 
	  /*for(int i=0;i<ROW;i++){
	 	for(int j=0;j<ROW+1;j++){
	 		printf("%0.2lf ",sol[i][j]);
	 	}
	 	printf("\n");
	 }*/
	 solution();
	 
	 printf("Solution matrix: \n");
	 for(int i=0;i<ROW;i++){
	 	printf("%0.2lf\n",sol[i][ROW]);
	 }
		
	return 0;
}
