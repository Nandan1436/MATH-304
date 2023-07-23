#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)

int main(){
	double a,b,e,c;
	int i=1;
	a=1.25,b=1.5,e=10.0e-6;
	printf("--------------------------------------------------------------------------------------------------\n");
	printf("Iter        a               b               c               f(a)           f(b)             f(c) \n");
	printf("--------------------------------------------------------------------------------------------------\n");
	while(1){
		c=(a+b)/2;
		printf("%d\t %0.6lf\t %0.6lf\t %0.6lf\t %0.6lf\t %0.6lf\t %0.6lf\n",i,a,b,c,f(a),f(b),f(c));
		if(fabs(f(c))<=e)break;
		if(f(a)*f(c)<0)b=c;
		else a=c;
		i++;
	}
	printf("--------------------------------------------------------------------------------------------------\n");
	printf("Approximate root = %lf\n",c);
	return 0;
}
