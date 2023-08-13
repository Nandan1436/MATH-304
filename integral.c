#include<stdio.h>
#include<math.h>
#define f(x) ((x)*(x)+1)

void trapezoidal(int n,double a,double b){
	int i;
	double h=(b-a)/n,x[n+1],y[n+1],I=0,X;
	x[0]=a;
	y[0]=f(x[0]);
	for(int i=1;i<n;i++){
		x[i]=x[i-1]+h;
		y[i]=f(x[i]);
	}
	x[n]=b;
	y[n]=f(x[n]);
	for(i=1;i<n;i++){
		I+=y[i];
	}
	X=y[0]+y[n];
	printf("Integral using Trapezoidal: %.6lf\n",(h*(X+2*I))/2);
}

void simpsons(int n,double a,double b){
	int i;
	if(n%2!=0)n++;
	double h=(b-a)/n,x[n+1],y[n+1],X,E=0,O=0;
	x[0]=a;
	y[0]=f(x[0]);
	for(i=1;i<n;i++){
		x[i]=x[i-1]+h;
		y[i]=f(x[i]);
	}
	x[n]=b;
	y[n]=f(x[n]);
	X=y[0]+y[n];	
	for(i=1;i<=n-1;i=i+2){
		O+=y[i];
	}
	for(i=2;i<=n-2;i=i+2){
		E+=y[i];
	}
	printf("Integral using Simpsons: %.6lf\n",(h*(X+2*E+4*O))/3);
	
}

int main(){
	double a,b,h;
	int n=10;
	a=0;
	b=2;
	
	trapezoidal(n,a,b);
	simpsons(n,a,b);
	
	return 0;
}
