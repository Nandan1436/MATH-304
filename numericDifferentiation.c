#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)+1)

int main(){
	double a,b,h;
	int n,i;
	a=0.0,b=2.0;
	n=10;
	h=(b-a)/n;
	double x[n+1],y[n+1];
	x[0]=a;
	y[0]=f(x[0]);
	for(i=1;i<n;i++){
		x[i]=x[i-1]+h;
		y[i]=f(x[i]);
	}
	x[i]=b;
	y[i]=f(x[i]);
	
	printf("-------------------------------------------------------\n");
	printf("i\t     x[i]\t    f[x[i]]\t   f'[x[i]]\n");
	printf("-------------------------------------------------------\n");
	for(i=0;i<=n;i++){
		printf("%d\t %10.6lf\t %10.6lf\t ",i,x[i],y[i]);
		if(i==0)printf("%10.6lf\n",(y[1]-y[0])/(x[1]-x[0]));
		else if(i==n)printf("%10.6lf\n",(y[n]-y[n-1])/(x[n]-x[n-1]));
		else printf("%10.6lf\n",(y[i]-y[i-1])/(x[i]-x[i-1]));
	}
	printf("-------------------------------------------------------\n");
	
	return 0;
}
