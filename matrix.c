#include<stdio.h>
#include<math.h>
#define ROW 3
#define COL 4

void printMatrix(double matrix[ROW][COL])
{
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			printf("%10.2lf  ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printInverse(double matrix[ROW][ROW+ROW])
{
	for(int i=0;i<ROW;i++){
		for(int j=ROW;j<ROW+ROW;j++){
			printf("%10.2lf  ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void gaussianElimination2(double matrix[ROW][ROW+ROW])
{
	int numRow=ROW;
	int numCol=COL-1;
	int col,row;
	for(col=0;col<numCol;col++){
		for(row=col+1;row<numRow;row++){
			double factor=matrix[row][col]/matrix[col][col];
			for(int j=0;j<ROW+ROW;j++){
				matrix[row][j]-=factor*matrix[col][j];
			}
			
		}
		printInverse(matrix);
	}
}

void backward2(double matrix[ROW][ROW+ROW])
{
	int numRow=ROW;
	int numCol=COL-1;
	int col,row;
	for(col=numCol-1;col>=0;col--){
		for(row=col-1;row>=0;row--){
			double factor=matrix[row][col]/matrix[col][col];
			for(int j=0;j<ROW+ROW;j++){
				matrix[row][j]-=factor*matrix[col][j];
			}
			
		}
		printInverse(matrix);
	}
	col=0;
	for(row=0;row<ROW;row++){
		double factor=matrix[col][col];
		for(int j=0;j<ROW+ROW;j++){
			matrix[row][j]/=factor;
		}
		col++;
	}
	printInverse(matrix);
	
}

void gaussianElimination(double matrix[ROW][COL])
{
	int numRow=ROW;
	int numCol=COL-1;
	int col,row;
	for(col=0;col<numCol;col++){
		for(row=col+1;row<numRow;row++){
			double factor=matrix[row][col]/matrix[col][col];
			for(int j=0;j<COL;j++){
				matrix[row][j]-=factor*matrix[col][j];
			}
			
		}
		printMatrix(matrix);
	}
}

double determinant(double matrix[ROW][COL])
{
	double determinant=1;
	for(int i=0;i<COL-1;i++){
		determinant*=matrix[i][i];
	}
}

void backward(double matrix[ROW][COL])
{
	int numRow=ROW;
	int numCol=COL-1;
	int col,row;
	for(col=numCol-1;col>=0;col--){
		for(row=col-1;row>=0;row--){
			double factor=matrix[row][col]/matrix[col][col];
			for(int j=0;j<COL;j++){
				matrix[row][j]-=factor*matrix[col][j];
			}
			
		}
		printMatrix(matrix);
	}
	col=0;
	for(row=0;row<ROW;row++){
		double factor=matrix[col][col];
		for(int j=0;j<COL;j++){
			matrix[row][j]/=factor;
		}
		col++;
	}
	printMatrix(matrix);
	
}

int main()
{
	double augmentedMatrix[ROW][COL]={
		{4,1,1,8},
		{2,5,2,3},
		{1,2,4,11}
	};
	printf("Original augmented matrix: \n");
	printMatrix(augmentedMatrix);
	printf("Gaussian Elimination: \n");
	gaussianElimination(augmentedMatrix);
	
	double deter = determinant(augmentedMatrix);
	printf("Determinant is: %0.2lf\n",deter);
	
	printf("Backward elimination: \n");
	backward(augmentedMatrix);
	printf("Solution: \n");
	for(int i=0;i<ROW;i++){
		printf("%10.2lf\n",augmentedMatrix[i][COL-1]);
	}
	double Matrix[ROW][ROW+ROW]={
		{4,1,1,1,0,0},
		{2,5,2,0,1,0},
		{1,2,4,0,0,1}
	};
	gaussianElimination2(Matrix);
	backward2(Matrix);
	
	printInverse(Matrix);
	
	return 0;
}
