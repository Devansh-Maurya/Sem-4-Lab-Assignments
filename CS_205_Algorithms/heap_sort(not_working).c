#include<stdio.h>

#define M 20

void insert_in_heap(int [], int, int);
void delete_from_heap(int [], int);

int main(void)
{
	int num, heap[M], n, i;
	
	printf("How many numbers you want to enter? ");
	scanf("%d",&n);
	
	printf("Enter the numbers: ");
	for(i=0; i<n; i++)
	{
		scanf("%d",&num);
		insert_in_heap(heap, num, i+1);
	}
	
	for(i=1; i<=n; i++)
		printf("%d ",heap[i]);
		
	for(i=n; i>0; i--)
		delete_from_heap(heap, i);
	
	printf("The sorted array is as follows: ");
	for(i=1; i<=n; i++)
		printf("%d ",heap[i]);
	
	return 0;
}

void insert_in_heap(int heap[], int val, int n)
{
	heap[n]= val;
	
	int child_position= n, parent;
	n++;
	
	while(child_position> 1)
	{
		parent= child_position/2;
		
		if(heap[parent]< heap[child_position])
		{
			heap[child_position]= heap[parent]^heap[child_position];	//Swap parent and child
			heap[parent]= heap[parent]^heap[child_position];
			heap[child_position]= heap[parent]^heap[child_position];
			
			child_position= parent;
		}
		else
			break;
	}
}

void delete_from_heap(int heap[], int n)
{
	printf("Entering delete function\n");
	
	heap[1]=heap[1]^heap[n];
	heap[n]=heap[1]^heap[n];
	heap[1]=heap[1]^heap[n];
	
	n--;
		printf("Entering delete function\n");
	int parent=1, left_child= 2, right_child= 3, i;
		printf("Entering delete function\n");
	while(left_child<= n)
	{
		printf("Execution: %d\n",n);
		if((heap[parent]>= heap[left_child])&&(heap[parent]>= heap[left_child]))
			break;

		if(heap[right_child]<= heap[left_child])
		{
			heap[left_child]= heap[left_child]^heap[parent];
			heap[parent]= heap[left_child]^heap[parent];
			heap[left_child]= heap[left_child]^heap[parent];
			
			parent= left_child;
		}
		else
		{
			heap[right_child]= heap[right_child]^heap[parent];
			heap[parent]= heap[right_child]^heap[parent];
			heap[right_child]= heap[right_child]^heap[parent];
			
			parent= right_child;
		}
		for(i=1; i<=4; i++)
		printf("%d ",heap[i]);
		left_child= parent*2;
		right_child= left_child+1;
	}
}

