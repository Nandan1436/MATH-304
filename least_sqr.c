#include<stdio.h>
#include<math.h>

int main()
{
    int n,r;
    scanf("%d %d",&n,&r);
    r++;
    double table[n][2];
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&table[i][0],&table[i][1]);
    }
    double c[r+1],b[n];
    double mat[n][r],mat_trans[r][n];
    double m1[r][r],m2[r];
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            if(j==0)mat[i][j]=1;
            else mat[i][j]=pow(table[i][0],j);
        }
        b[i]=table[i][1];
    }
    for(int j=0;j<r;j++){
        for(int i=0;i<n;i++){
            mat_trans[j][i]=mat[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<n;k++){
                m1[i][j]+=mat_trans[i][k]*mat[k][j];
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<n;j++){
            m2[i]+=mat_trans[i][j]*b[j];
        }
    }

	double aug_mat[r][r+1];
	for(int i=0;i<r;i++){
        for(int j=0;j<r+1;j++){
            if(j==r)aug_mat[i][j]=m2[i];
            else {
                aug_mat[i][j]=m1[i][j];
            }
        }
	}

	for(int i=0;i<r;i++){
        for(int j=0;j<r+1;j++)
            printf("%lf ",aug_mat[i][j]);
        printf("\n");
	}
	for(int i=0;i<r;i++){
        for(int j=i+1;j<r;j++){
            double factor=aug_mat[j][i]/aug_mat[i][i];
            for(int k=0;k<r+1;k++){
                aug_mat[j][k]-=factor*aug_mat[i][k];
            }
        }
	}

	for (int i=r-1;i>=0;i--) {
        c[i]=aug_mat[i][r];
        for (int j=i+1;j<r;j++) {
            c[i]-=aug_mat[i][j]*c[j];
        }
        c[i]/=aug_mat[i][i];
    }
    printf("Solution: \n");
    for(int i=0;i<r;i++)printf("%5.3lf\n",c[i]);


    return 0;
}
