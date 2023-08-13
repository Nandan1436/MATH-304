#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) sqrt(x)
#define g(x) (x)*(x)
#define h(x) f(x)-g(x)
#define e 10.0e-6

double bisec(double a,double b){
	if(h(a)*h(b)>0){
		printf("No root.\n");
		exit(EXIT_FAILURE);
	}
	double c;
	while(1){
		c=(a+b)/2;
		if(fabs(h(c))<=e){
			return c;
		}
		if(h(a)*h(c)<0)b=c;
		else a=c;
	}
}
double simpsons(int n,double a,double b){
	int i;
	if(n%2!=0)n++;
	double z=(b-a)/n,x[n+1],y[n+1],X,E=0,O=0;
	x[0]=a;
	y[0]=h(x[0]);
	for(i=1;i<n;i++){
		x[i]=x[i-1]+z;
		y[i]=h(x[i]);
	}
	x[n]=b;
	y[n]=h(x[n]);
	X=y[0]+y[n];	
	for(i=1;i<=n-1;i=i+2){
		O+=y[i];
	}
	for(i=2;i<=n-2;i=i+2){
		E+=y[i];
	}
	return (z*(X+2*E+4*O))/3;
}

int main(){
	int n=1000;
	double a,b,h;	
	a=0,b=bisec(0.8,1.2);	
	printf("Area between f(x) and g(x) is: %0.6lf\n",simpsons(n,a,b));
		
	return 0;
}
