//Multiplication of a matrix with its transpose

#include<stdio.h>
#include<stdlib.h>

#define S 10
#define D 4

int c[S][S];

void matrix_mult(int [S][S], int [S][S], int []);


int main()
{
	int a[S][S], b[S][S], dimension[D], i, j;

	printf("Enter the dimension of matrix A: ");
	for(i=0; i<2; i++)
        scanf("%d", &dimension[i]);
    
    printf("Enter the dimension of matrix B: ");
	for(i=2; i<4; i++)
        scanf("%d", &dimension[i]);

    if(dimension[1]!=dimension[2])
    {
        printf("\nDimension mismatch!\nMatrix multiplication not possible!\n");
        exit(0);
    }

	printf("Enter matrix A:\n");
	
	for(i=0;i <dimension[0]; i++)
		for(j=0; j<dimension[1]; j++)
			scanf("%d",&a[i][j]);

    printf("Enter matrix B:\n");

    for(i=0;i <dimension[2]; i++)
		for(j=0; j<dimension[3]; j++)
			scanf("%d",&b[i][j]);

	printf("\nEntered matrix A\n\n");
	for(i=0;i <dimension[0]; i++)
	{
		for(j=0; j<dimension[1]; j++)
			printf("%d ",a[i][j]);
		
		printf("\n");
	}

    printf("\nEntered matrix B\n\n");
	for(i=0;i <dimension[2]; i++)
	{
		for(j=0; j<dimension[3]; j++)
			printf("%d ",b[i][j]);
		
		printf("\n");
	}

	matrix_mult(a, b, dimension);

	printf("\nThe product is:\n\n");
	for(i=0;i <dimension[0]; i++)
	{
		for(j=0; j<dimension[3]; j++)
			printf("%d ",c[i][j]);

		printf("\n");
	}

	return 0;
}

void matrix_mult(int a[S][S], int b[S][S], int dimension[])
{
	int i, j, k;
    
	for(i=0;i <dimension[0]; i++)
		for(j=0; j<dimension[3]; j++)
			c[i][j]= 0;

	for(i=0;i <dimension[0]; i++)
		for(j=0; j<dimension[3]; j++)
			for(k=0; k<dimension[1]; k++)
				c[i][j]+= a[i][k]*b[k][j];
}