#include<stdio.h>

#define X 10
#define Y 10

int main()
{
	int n, i, j, k; 
	float x[X], y[Y], squareY, squareAlpha, squareBeta, alpha, beta, alphaBeta, determinant, B[2], invA[2][2], C[2];
	
	printf("Enter the value of n: ");
	scanf("%d",&n);
	
	printf("Enter the points: ");
	for(i=0; i<n; i++)
	{
		printf("Enter x%d: ", i);
		scanf(" %f",&x[i]);
		printf("Enter y%d: ", i);
		scanf(" %f",&y[i]);
		printf("\n");
	}

	//All the variables are the coefficients of Alpha. beta or alphabeta from the initial equation
	
	squareY=0;					//Not needed
	for(i=0; i<n; i++)
		squareY+=y[i]*y[i];
	
	squareAlpha= n;
	
	squareBeta=0;
	for(i=0; i<n; i++)
		squareBeta+= x[i]*x[i];
	
	alphaBeta=0;
	for(i=0; i<n; i++)
		alphaBeta+= x[i]*2;
		
	alpha=0;
	for(i=0; i<n; i++)
		alpha+= -y[i]*2;
	
	beta= 0;
	for(i=0; i<n; i++)
		beta+= -y[i]*2*x[i];
		
	B[0]= -alpha;
	B[1]= -beta;
	
	determinant= 4*squareAlpha*squareBeta - alphaBeta*alphaBeta;
	
	invA[0][0]= 2*squareBeta / determinant;
	invA[0][1]= -alphaBeta / determinant;
	invA[1][0]= -alphaBeta / determinant;
	invA[1][1]= 2*squareAlpha / determinant;
	
	for(i=0; i<2; i++)
		for(j=0; j<1; j++)
		{
			C[i]=0;
			for(k=0; k<2; k++)
				C[i]+=invA[i][k]*B[k];
		}
		
	printf("The equation is:\ny= %f + %f*x\n", C[0], C[1]);
	
	return 0;
}
	
	
	
	
	
	
	


