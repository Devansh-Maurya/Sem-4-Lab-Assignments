#include<stdio.h>
#include<math.h>

int main()
{
	double tmin= 0, tmax= 6.28, dtheta, i=1 , theta, y, n=1001, t, c;

	dtheta= (-tmin + tmax)/n;

	FILE *sine= fopen("sin", "w");
	FILE *cosine= fopen("cos", "w");
	FILE *tangent= fopen("tan", "w");

	do
	{
		theta= tmin+ (i-1)*dtheta;
		y= sin(theta);
		t= tan(theta);
		c= cos(theta);

		i++;
		n--;
		
		fprintf(sine, "theta= %f, sin(theta)= %8f\n", theta, y);
		fprintf(cosine, "theta= %f, cos(theta)= %8f\n", theta, c);
		fprintf(tangent, "theta= %f, tan(theta)= %8f\n", theta, t);
	}
	while(n>0);

	return 0;
}
