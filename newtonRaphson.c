#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
#define df(x) (3*(x)*(x)+8*(x))

int main(){
	double x,x1,e;
	int i=1;
	x=1.5,e=10.0e-6;
	printf("-----------------------------------------------------------------------------------------\n");
	printf("Iter        x0              x1            f(x0)            f'(x0)          f(x1)\n");
	printf("-----------------------------------------------------------------------------------------\n");
	while(1){
		x1=x-(f(x)/df(x));
		printf("%d\t %0.6lf\t %0.6lf\t %0.6lf\t %0.6lf\t %0.6lf\t\n",i,x,x1,f(x),df(x),f(x1));
		if(f(x1)<=e)break;
		else x=x1;
		i++;
	}
	printf("-----------------------------------------------------------------------------------------\n");
	printf("Approximate root = %lf\n",x1);
	return 0;
}
