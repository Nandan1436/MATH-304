#include<stdio.h>
#include<math.h>
#define f(x) sin(x)
#define PI 3.14159265

int main(){
	int n=100,i;
	double a=0,b=2*PI,h,x[n+1],y[n+1];
	h=(b-a)/n;
	printf("\"x\",\"f(x)\",\"f'(x)\"\n");
	
	x[0]=a;
	y[0]=f(x[0]);
	for(i=1;i<n;i++){
		x[i]=x[i-1]+h;
		y[i]=f(x[i]);
	}
	x[i]=b;
	y[i]=f(x[i]);
	
	for(i=0;i<=n;i++){
		printf("%10.6lf,%10.6lf,",x[i],y[i]);
		if(i==0)printf("%10.6lf\n",(y[1]-y[0])/(x[1]-x[0]));
		else if(i==n)printf("%10.6lf\n",(y[n]-y[n-1])/(x[n]-x[n-1]));
		else printf("%10.6lf\n",(y[i]-y[i-1])/(x[i]-x[i-1]));
	}
	
	
	return 0;
}
