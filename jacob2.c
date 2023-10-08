#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ROW 3
#define e 10.0e-6

double A[ROW][ROW]={{4,1,1},{2,5,2},{1,2,4}};
double B[ROW]={8,3,11};
double xN[ROW]={0,0,0};
double xO[ROW]={0,0,0};

void doCalc(int i)
{
	double sum=0;
	for(int j=0;j<ROW;j++){
		if(j!=i)sum+=A[i][j]*xO[j];
	}
	xN[i]=(B[i]-sum)/A[i][i];
}

int main()
{
	int itr=1;
	
	printf("---------------------------------------------------------\n");
   	printf("Iter\t\tx1\t\tx2\t\tx3\n");
    	printf("---------------------------------------------------------\n");
	
	while(1)
	{
		for(int i=0;i<ROW;i++){
			doCalc(i);
		}
		printf("%d\t%10.2lf\t%10.2lf\t%10.2lf\n",itr,xN[0],xN[1],xN[2]);
		if(fabs(xN[0]-xO[0])<e && fabs(xN[1]-xO[1])<e && fabs(xN[2]-xO[2])<e)
        	{
        	    break;
        	}
        	itr++;
        	for(int i=0;i<ROW;i++){
        		xO[i]=xN[i];
        	}
	}
	printf("---------------------------------------------------------\n");
	
	printf("Solution matrix: \n");
    	for(int i=0;i<ROW;i++){
        	printf("%8.2lf\n",xN[i]);
    	}
	
	
	return 0;
}
