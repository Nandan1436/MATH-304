#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ROW 3
#define e 10.0e-3

int main()
{
    double A[ROW][ROW]={{4,1,1},{2,5,2},{1,2,4}};
    double B[ROW][1]={{8},{3},{11}};

    double diagA[ROW][ROW],diagInv[ROW][ROW];
    double x0[ROW][1]={{0},{0},{0}},x1[ROW][1];
    double sum=0;

    int i,j,k;

    for(i=0;i<ROW;i++){
        for(j=0;j<ROW;j++){
            if(i!=j)sum+=A[i][j];
        }
        if(A[i][i]<=sum){
            printf("Solution may not exist!\n");
            exit(1);
        }
        sum=0;
    }

    for(i=0;i<ROW;i++){
        for(j=0;j<ROW;j++){
            if(i==j){
                diagA[i][j]=A[i][j];
                diagInv[i][j]=1/diagA[i][j];
            }
            else {
                diagA[i][j]=0;
                diagInv[i][j]=0;
            }
        }
    }

    printf("---------------------------------------------------------\n");
    printf("Iter\t\tx1\t\tx2\t\tx3\n");
    printf("---------------------------------------------------------\n");

    int itr=1;
    while(1){
        double temp[ROW][1]={{0},{0},{0}};
        double diff[ROW][1]={{0},{0},{0}};
        for(i=0;i<ROW;i++){
            for(k=0;k<ROW;k++){
                temp[i][0]+=A[i][k]*x0[k][0];
            }
        }
        for(i=0;i<ROW;i++){
            temp[i][0]=B[i][0]-temp[i][0];
        }
        for(i=0;i<ROW;i++){
            for(k=0;k<ROW;k++){
                diff[i][0]+=diagInv[i][k]*temp[k][0];
            }
        }
        for(i=0;i<ROW;i++){
            x1[i][0]=x0[i][0]+diff[i][0];
        }
        printf("%d\t%10.2lf\t%10.2lf\t%10.2lf\n",itr,x1[0][0],x1[1][0],x1[2][0]);

        if(sqrt(pow(x1[0][0]-x0[0][0],2) + pow(x1[1][0]-x0[1][0],2) + pow(x1[2][0]-x0[2][0],2)) / sqrt(pow(x1[0][0],2) + pow(x1[1][0],2) + pow(x1[2][0],2) ) < e)
        {
            break;
        }

        for(i=0;i<ROW;i++){
            x0[i][0]=x1[i][0];
        }
        itr++;
        if(itr>100)break;
    }
    printf("---------------------------------------------------------\n");

    printf("Solution matrix: \n");
    for(i=0;i<ROW;i++){
        printf("%8.2lf\n",x1[i][0]);
    }

    return 0;
}