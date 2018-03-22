//Multiplication of a matrix with its transpose

#include<stdio.h>
#include<complex.h>

#define S 10

double complex c[S][S];

void matrix_transpose_mult(int [S][S], int);

int main()
{
	double complex a[S][S];
	int n, i, j;

	printf("Enter the matrix dimension: ");
	scanf("%d", &n);

	printf("Enter the matrix: ");
	
	for(i=0;i <n; i++)
		for(j=0; j<n; j++)
			scanf("%fi",&a[i][j]);

	printf("\nYou entered the matrix:\n\n");
	for(i=0;i <n; i++)
	{
		for(j=0; j<n; j++)
			printf("%fi ",a[i][j]);
		
		printf("\n");
	}

	//Conjugate
	for(i=0;i <n; i++)
		for(j=0; j<n; j++)
			if(cimag(a[i][i])
				a[i][i]= -a[i][i];

	printf("\nTranspose of matrix:\n\n");
	for(i=0;i <n; i++)
	{
		for(j=0; j<n; j++)
			printf("%fi ",a[j][i]);
		
		printf("\n");
	}

	matrix_transpose_mult(a, n);

	printf("\nThe product is:\n\n");
	for(i=0;i <n; i++)
	{
		for(j=0; j<n; j++)
			printf("%fi ",c[i][j]);

		printf("\n");
	}

	return 0;
}

void matrix_transpose_mult(double complex a[S][S], int n)
{
	int i, j, k;

	for(i=0;i <n; i++)
		for(j=0; j<n; j++)
			c[i][j]= 0;

	for(i=0;i <n; i++)
		for(j=0; j<n; j++)
			for(k=0; k<n; k++)
				//c[i][j]+= a[i][k]*a[j][k];
				c[i][j]+= a[k][i]*a[k][j];
}
