#include <stdio.h>
#include <float.h>
#include <math.h>

#define e 1.0e-6
#define R 3

double x0[R] = {1, 0, 0};
double old = DBL_MAX; 

void matrixVectorMultiply(double matrix[R][R], double result[R]) {
    
}

double findMax(double res[R]) {
    double maxVal = DBL_MIN;
    for (int i = 0; i < R; i++) {
        maxVal = fmax(maxVal, res[i]);
    }
    return maxVal;
}

double powerIter(double matrix[R][R]) {
    double result[R], eigenVal;

    while (1) {

        for (int i = 0; i < R; i++) {
        	result[i] = 0;
        	for (int j = 0; j < R; j++) {
            	result[i] += matrix[i][j] * x0[j];
        	}
    	}
    	
        eigenVal = findMax(result);

        if (fabs(eigenVal - old) < e) {
            break;
        }

        for (int i = 0; i < R; i++) {
            result[i] /= eigenVal;
            x0[i] = result[i];
        }
        old = eigenVal;
    }
    return eigenVal;
}

int main() {
    double mat[R][R] = {
        {2, -1, 0},
        {-1, 2, -1},
        {0, -1, 2}
    };

    printf("Maximum eigenvalue: %lf\n", powerIter(mat));
    for(int i=0;i<R;i++)printf("%lf ",x0[i]);
    printf("\n");


    return 0;
}
