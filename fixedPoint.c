#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
#define g(x) sqrt((10-(x)*(x)*(x))/4)

int main(){
	double x0,x1,e;
	int i=1;
	x0=1.5,e=10.0e-6;
	printf("--------------------------------------------------------------------------\n");
	printf("Iter        x0              x1            g(x0)            f(x1)          \n");
	printf("--------------------------------------------------------------------------\n");
	while(1){
		x1=g(x0);
		printf("%d\t %10.6lf\t %10.6lf\t %10.6lf\t %10.6lf\t\n",i,x0,x1,g(x0),f(x1));
		if(fabs(f(x1))<=e)break;
		x0=x1;
		i++;
	}
	printf("--------------------------------------------------------------------------\n");
	printf("Approximate root = %lf\n",x1);
	return 0;
}
