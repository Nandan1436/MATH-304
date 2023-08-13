#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)

int main(){
	double x0,x1,x2,e;
	int i=1;
	x0=1.5,x1=2.0,e=10.0e-6;
	printf("--------------------------------------------------------------------------------------------------\n");
	printf("Iter        x0               x1             x2              f(x0)          f(x1)            f(x2) \n");
	printf("--------------------------------------------------------------------------------------------------\n");
	while(1){
		x2=(x0*f(x1) - x1*f(x0)) / (f(x1)-f(x0));
		printf("%d\t %0.6lf\t %0.6lf\t %0.6lf\t %0.6lf\t %0.6lf\t %0.6lf\n",i,x0,x1,x2,f(x0),f(x1),f(x2));
		if( fabs(f(x2))<=e ) break;
		x0=x1;
		x1=x2;
		i++;
	}
	printf("--------------------------------------------------------------------------------------------------\n");
	printf("Approximate root = %lf\n",x2);
	return 0;
}