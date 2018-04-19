#include<stdio.h>

#define EPSILON 0.00001

float f(float);
float derivativef(float);

int main()
{
	float x;
	
	printf("Enter the initial guess: ");
	scanf("%f", &x);
	
	while((f(x) > EPSILON) || (f(x) < -EPSILON)) {
		printf("The value of f(x) at x = %f : %f\n", x, f(x));
		x = x - f(x)/derivativef(x);
	}
	
	printf("The root of f(x) is: %.5f\n", x);
	 
	return 0;
}

float f(float x) {
	return (x*x*(x*x - 2) - 6);
}

float derivativef(float x) {
	return 4*x*(x*x - 1);
}
