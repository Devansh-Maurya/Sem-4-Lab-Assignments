/********************************************************************************************************************************/
/*

Name		: Devansh Maurya
Roll No.	: B16CS024
Algorithm	: Finding kth largest element in an unsorted array either by sorting the array using Quick Sort or without 			  sorting using Quick Select
Laboratory	: CS255

*/
/*********************************************************************************************************************************/

#include<stdio.h>

#define M 20

void quick_sort(int [], int, int);
int partition(int [], int , int);
int k_largest_in_sorted(int [], int, int);
int k_largest_in_unsorted(int [], int, int, int);
int k_smallest_unsorted(int [], int, int, int);
int k_smallest_in_unsorted(int [], int, int, int);

int main(void)
{
	int a[M], n, i, k, k_largest;
	char choice, capture;
	
	printf("How many numbers you want to enter? ");
	scanf("%d",&n);
	scanf("%c",&capture);
	
	printf("Are the numbers distinct? (y/n) ");
	scanf("%c",&choice);
	
	printf("Enter the numbers: ");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	printf("Enter the value of k: ");
	scanf("%d",&k);
	
	if((choice=='y')||(choice=='Y'))
	{
		printf("Using unsorted\n");
		k_largest= k_largest_in_unsorted(a, 0, n-1, k);
	}
	else
	{
		printf("Using sorted\n");
		quick_sort(a, 0, n-1);
		k_largest= k_largest_in_sorted(a, n, k);
	}
	
	/*printf("The sorted array is as follows: ");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);*/

	return 0;
}

void quick_sort(int a[], int beg, int end)
{
	int pivot;
	
	if(beg<end)
	{
		pivot= partition(a, beg, end);
		quick_sort(a, beg, pivot-1);
		quick_sort(a, pivot+1, end);
	}
}

int partition(int a[], int beg, int end)
{
	int flag=0, left, loc, right= end, temp;		//loc is the location of the pivot
	left=loc= beg;						//left points to the elements left of the loc
								//right points to the elements right of loc
	while(flag!=1)
	{
		while((a[loc]<=a[right])&&(loc!=right))
		{
			right--;
		}
		if(loc==right)
		{
			flag=1;
		}
		else if(a[loc]>a[right])
		{
			temp = a[loc];
			a[loc] = a[right];
			a[right] = temp;
			loc = right;
		}
		
		if(flag==0)
		{
			while((a[loc]>=a[left])&&(loc!=left))
			{
				left++;
			}
			
			if(loc==left)
			{
				flag=1;
			}
			else if(a[loc]<a[left])
			{
				temp = a[loc];
				a[loc] = a[left];
				a[left] = temp;
				loc = left;
			}
		}
	}
	
	return loc;
}
int k_largest_in_sorted(int a[], int n, int k)
{
	int j=1, i, largest; 
	
	if(k<=n)
	{
		largest= a[n-1];
	
		for(i=n-2; (i>=0)&&(j<k); i--)
		{
			if(a[i]< largest)
			{
				largest= a[i];
				j++;
			}
		}
	
		if(j==k)
		{
			printf("The k'th largest element is: %d\n", largest);
			return largest;
		}
		else if(i<0)
		{
			printf("%d distinct elements are not present in the array\n", k);
			return -1;
		}
	}
	else
	{
		printf("Value of k is larger than the total number of elements present in the array");
		return -1;
	}
}

int k_smallest_in_unsorted(int a[], int beg, int end, int k)
{
	int pivot, largest;
	
	if(k>end+1)
	{
		printf("Value of k is larger than the total number of elements present in the array");
		return -1;
	}
	else
	{
		pivot= partition(a, beg, end);
	
		if(pivot-beg==k-1)
		{
			printf("The k'th largest element is: %d\n", a[pivot]);
			return a[pivot];
		}
		else if(pivot-beg<k-1)
		{
			return k_smallest_unsorted(a, pivot+1, end, k-(pivot+1)+beg); ////
		}
		else if(pivot-beg>k-1)
		{
			return k_smallest_unsorted(a, beg, pivot-1, k);
		}
	}
}

int k_smallest_unsorted(int a[], int beg, int end, int k)
{
	int pivot, largest;
	printf("Dont want it\n");
	pivot= partition(a, beg, end);
	
	if(pivot-beg==k-1)
	{
		printf("The k'th largest element is: %d\n", a[pivot]);
		return a[pivot];
	}
	else if(pivot-beg<k-1)
	{
		return k_smallest_unsorted(a, pivot+1, end, k-(pivot+1)+beg);
	}
	else if(pivot-beg>k-1)
	{
		return k_smallest_unsorted(a, beg, pivot-1, k);
	}
}

int k_largest_in_unsorted(int a[], int beg, int end, int k)
{
	if(k>end+1)
	{
		printf("Value of k is larger than the total number of elements present in the array");
		return -1;
	}
	else
		return k_smallest_in_unsorted(a, beg, end, end-k+2);
}
