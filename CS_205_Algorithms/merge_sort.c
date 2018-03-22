/*********************************************************************************************************************************/
/*

Name: Devansh Maurya
Roll No.: B16CS024
Algorithm: Merge Sort
Laboratory: CS255

*/
/*********************************************************************************************************************************/

#include<stdio.h>

#define M 20

void merge_sort(int [], int, int);
void merge(int [], int , int, int);

int main(void)
{
	int a[M], n, i;
	
	printf("How many numbers you want to enter? ");
	scanf("%d",&n);
	
	printf("Enter the numbers: ");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
	
	merge_sort(a, 0, n-1);
	
	printf("The sorted array is as follows: ");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}

void merge_sort(int a[], int beg, int end)
{
	int mid;
	if(beg<end)
	{
		mid= (beg+end)/2;
		
		merge_sort(a, beg, mid);
		merge_sort(a, mid+1, end);
		merge(a, beg, mid, end);
	}
}

void merge(int a[], int beg, int mid, int end)
{
	int temp[M], i=beg, j=mid+1, k=beg;
	
	while((i<=mid)&&(j<=end))
		if(a[i]<a[j])
			temp[k++]=a[i++];		//k is the index for the temporary array
		else
			temp[k++]=a[j++];
	
	if(i>mid)
		while(j<=end)
			temp[k++]=a[j++];
	else
		while(i<=mid)
			temp[k++]=a[i++];
	
	for(i=beg; i<k; i++)
		a[i]=temp[i];
}
