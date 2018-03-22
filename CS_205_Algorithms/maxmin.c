#include<stdio.h>

#define M 10

void maxmin(int* , int, int);

//int val[2], *right, *left;

int min,max;

int main()
{
	int arr[M], n, i, *result;
	
	printf("How many numbers you want to enter? ");
	scanf("%d",&n);
	
	printf("Enter the numbers: ");
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	
	maxmin( arr, 0, n-1);
	
	printf("The largest number is %d\n", max);
	printf("The smallest number is %d", min);
	
	return 0;
}

void maxmin( int a[], int beg, int end)
{
	int mid, min1, max1;
	
	if(end-beg+1== 1)
	{
		min= a[beg];
		max= a[beg];

	}
	else if(end-beg+1== 2)
	{
		if(a[beg]> a[end])
		{
			min= a[end];
			max= a[beg];
		}
		else
		{
			min= a[beg];
			max= a[end];
		}
	}
	
	else
	{
		mid= (beg+end)/2;
		
		maxmin(a, beg, mid);
		min1= min;
		max1= max;
		
		maxmin(a, mid+1, end);
		
		if(min1< min)
			min= min1;
		
		if(max1> max)
			max= max1;
	}
}
