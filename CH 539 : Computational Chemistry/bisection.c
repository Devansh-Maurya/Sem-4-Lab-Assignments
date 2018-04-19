#include<stdio.h>
#include<stdbool.h>

#define EPSILON 0.0001

float f(float);
bool check_sign(float, float);

int main()
{
	float a, b, c;
	int i=0, n, j=0;
	
	printf("Enter the range:\n");
	printf("Enter a: ");
	scanf( "%f", &a);
	printf("Enter b: ");
	scanf( "%f", &b);
	
	if(check_sign(f(a), f(b))) {
		printf("Incorrect interval\n");
		return 0;
	}
	
	printf("Enter the maximum iterations: ");
	scanf("%d", &n);
	
	while(i<n)
	{
		c = (a + b)/2;
		
		printf("f(x) = %f\n", f(c));
		
		if(((f(c) < EPSILON) && (f(c) > -EPSILON)) || (b - a)/2 < EPSILON) {
			printf("The root of f(x) is: %f\n", c);
			return 0;
		}
	
		printf("Iteration %d\n", i++);
		
		if(check_sign(f(c), f(a))) {	//If a and c have same sign
			a = c;
			printf("a= %f\n", c);
		}
		else {
			b = c;
			printf("a= %f\n\n", c);
		}
	}
	printf("Method failed.\n");
	 
	return 0;
}

float f(float x) {
	//return (x*x*(x*x - 2) - 6);
	return (x*x - 1)*x - 2;
}

//Returns true if both the numbers have the same sign
bool check_sign(float a, float b) {
	if(a*b > 0.0)
		return true;
	else
		return false;
}

