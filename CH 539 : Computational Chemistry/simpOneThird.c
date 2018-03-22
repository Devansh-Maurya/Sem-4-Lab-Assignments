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
	
	h= (b-a)/((n+1)/2-1); //Because in the loop it is taking an intermediate point between a and b, i.e., two adjacent points
	printf("Value of h: %f", h);
	
	for(i=0; a+i*h<b; i++)
	{
		ans= ans+ (h/3)*(func(a+(i+1)*h)+func(a+i*h)+ 4*func((a+i*h + a+(i+1)*h)/2))/2;
	}	
	printf("Answer is: %f\n",ans);
	
	return 0;	
}
	
float func(float x)
{
	return (3*x*x + 4*x + 1);
}
