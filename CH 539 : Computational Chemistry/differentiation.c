#include<stdio.h>

float func(float);

int main(void)
{
	float x, derivative1, derivative2, h, n;
	
	printf("Enter the value of x: ");
	scanf(" %f", &x);
	
	printf("Enter the value of n: ");
	scanf(" %f", &n);
	
	h=1/n;
	
	derivative1= (func(x+h) - func(x))/h;
	derivative2= (func(x+h) - func(x-h))/(2*h);
	
	printf("Derivative1: %f\nDerivative2= %f\n", derivative1, derivative2);
	
	return 0;
}

float func(float x)
{
	return (3*x*x + 4*x + 1);
}
