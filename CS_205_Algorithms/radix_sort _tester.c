#include <stdio.h>

#define S 10
#define M 20

int find_largest(int a[], int);
int no_of_positions(int);
void radix_sort(int a[], int);
void print_matrix(int (*)[]);

int main(void)
{
	int a[M], n, i;
	
	printf("How many numbers you want to enter? ");
	scanf("%d",&n);
	
	printf("Enter the numbers: ");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	radix_sort(a, n);
	
	printf("The sorted array is as follows: ");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	
	return 0;
}

int find_largest(int a[], int n)
{
	int i, largest=a[0];

	for(i=1; i<n; i++)
		if(a[i]>largest)
			largest=a[i];

	return largest;
}

int no_of_positions(int num)
{
	int positions=0;
	
	while(num>0)
	{
		positions++;
		num/=S;
	}

	return positions;
}

void radix_sort(int a[], int n)
{
	int largest, bucket[S][S], bucket_count[S], positions, pass, i, remainder, divisor= 1, j, k;
	
	largest= find_largest(a, n);
	
	positions= no_of_positions( largest);
	
	for(pass=0; pass<positions; pass++)
	{
		for(i=0; i<S; i++)
			bucket_count[i]= 0;
		
		for(i=0; i<n; i++)
		{
			remainder= (a[i]/divisor)%S;
			bucket[remainder][bucket_count[remainder]]= a[i];
			bucket_count[remainder]++;
		}
		
		print_matrix(bucket);
		printf("\n\n");
		
		i=0;
		for(k=0; k<S; k++)
		{
			for(j=0; j<bucket_count[k]; j++)
			{
				a[i++]= bucket[k][j];
			}
		}
		
		divisor= divisor*S;
	}
}

void print_matrix(int m[][S])
{
	int i,j;
	
	for(i=0; i<S; i++)
	{
		for(j=0;j<S; j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}
