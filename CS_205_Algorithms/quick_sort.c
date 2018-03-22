/*********************************************************************************************************************************/
/*

Name: Devansh Maurya
Roll No.: B16CS024
Algorithm: Quick Sort
Laboratory: CS255

*/
/*********************************************************************************************************************************/

#include<stdio.h>

#define M 20

void quick_sort(int [], int, int);
int partition(int [], int , int);

int main(void)
{
	int a[M], n, i;
	
	printf("How many numbers you want to enter? ");
	scanf("%d",&n);
	
	printf("Enter the numbers: ");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	quick_sort(a, 0, n-1);
	
	printf("The sorted array is as follows: ");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	
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
