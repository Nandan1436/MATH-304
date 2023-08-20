#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void printMatrix(int mat[3][3])
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d  ",mat[i][j]);
		}
		printf("\n");
	}
	
}

int main(){
	srand(time(0));
	clock_t start,end;
	double timeUsed;
	start=clock();
	int mat1[3][3],mat2[3][3],ans[3][3];
	int i,j,k;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			mat1[i][j]=rand()%10;
			mat2[i][j]=rand()%10;
			ans[i][j]=0;
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				ans[i][j]+=mat1[i][k]*mat2[k][j];
			}	
		}
	}
	end=clock();
	printf("First matrix: \n");
	printMatrix(mat1);
	printf("Second matrix: \n");
	printMatrix(mat2);
	printf("After multiplication: \n");
	printMatrix(ans);
	timeUsed=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Execution time: %lf\n",timeUsed);
	
	return 0;
}
