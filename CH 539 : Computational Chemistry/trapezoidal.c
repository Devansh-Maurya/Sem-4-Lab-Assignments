#include<stdio.h>

float func(float);

int main(void)
{
	float a, b, h, ans= 0, i, n;
	
	printf("Enter the limits: ");
	scanf(" %f",&a);
	scanf("%f",&b);
	
	printf("Enter the value of n: ");
	scanf("%f",&n);
	
	h= (b-a)/(n-1);
	printf("Value of h: %f", h);
	
	for(i=0; a+i*h<b; i++)
	{
		ans= ans+ h*(func(a+(i+1)*h)+func(a+i*h))/2;
	}	
	printf("Answer is: %f\n",ans);
	
	return 0;	
}
	
float func(float x)
{
	return (3*x*x + 4*x + 1);
}
